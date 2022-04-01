#include "pitches.h"
#include "songs.h"
#include <Keypad.h>

#define melodyPin 9
#define LED1 10
#define LED2 11
#define LED3 12
#define LED4 13
#define LED5 A5
#define LED6 A4
#define LED7 A3

//KEYBOARD SETUP
const byte ROWS = 4; 
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; 
byte colPins[COLS] = {4, 3, 2}; 
int keyToNote[8] = {494, 262,294,330,350,392,440,494};
int ledToPort[8] = {LED7,LED1, LED2, LED3, LED4, LED5, LED6, LED7};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  Serial.begin(9600);    
  pinMode(9, OUTPUT);    //SPEAKER
  pinMode(LED1, OUTPUT); //LEDs flash when music plays
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
}

String val = ""; //notes inputted by user
char temp;

boolean webPlayMode = 1;
boolean currentStatus = 0; // To indicate the status is tone mode or music mode

//MAIN LOOP
void loop() {
  
  while (Serial.available() > 0) { //Get control mode: online or arduino
      temp = Serial.read();
      
      if(temp == 'S' || temp == 'H'){
        webPlayMode = (temp == 'S')? 1: 0;
        
        digitalWrite(LED1, HIGH);
        delay(500); 
        digitalWrite(LED1, LOW);
      }
  }

  //---------- GET NOTES FROM USER/SERVER ------------- //
  
  if(webPlayMode){
    digitalWrite(LED7, HIGH); //indicates play mode
    
    while (Serial.available() > 0) { // If data is available to read,
      temp = Serial.read();

      if(temp == 'S' || temp == 'H'){
        webPlayMode = (temp == 'S')? 1: 0;
        break;
      }
      
      val.concat(temp); // read it and store it in val
      digitalWrite(LED3, HIGH);
      delay(100);
      digitalWrite(LED3, LOW);
    }

    if (val != ""){
      digitalWrite(LED7, LOW);
      delay(100);
      Serial.write("$");
      if (val.equals("M")){
    
        sing(1);
      } else if (val.equals("R")){
        
        sing(2);
      } else if (val.equals("G")){
       
        sing(3);
      } else {
        //send message to server arduino is busy
        parse(val);
        
      }
      Serial.write("%");
      val = "";
    }

  } else {
    digitalWrite(LED7, LOW);
  
   //---------- PLAYING FROM KEYPAD ------------- //
    char customKey = customKeypad.getKey();
    
    if (customKey == '*')            //SWITCH PLAY MODE (songs or keypad input)
    {
      currentStatus = !currentStatus;
      Serial.println("Play mode changed");
    }
  
    int key = customKey - '0';
    
    if (currentStatus == 0 && key > 0 && key <= 5) {       //PLAY PRESET MUSIC
      sing(key);
    } else if (key > 0 && key <= 7) {                        //PLAY NOTES THROUGH KEYPAD
      digitalWrite(ledToPort[key], HIGH);
      ToneTone(key);
      delay(50);
      digitalWrite(ledToPort[key], LOW);
    }
  }
}
  
//---------- LED FLASH WHEN NOTE PLAYED ------------- //
void LEDinput(char note, short pause){

  if (note == 'R' || note == 'r'){
    delay(pause);
  } else {
    int key = (note - 59)%7; //get note key
    digitalWrite(ledToPort[key], HIGH);
    delay(pause);
    digitalWrite(ledToPort[key], LOW);
  }
}

//---------- PLAY NOTE GIVEN KEY ------------- //
void ToneTone(short s){
  tone(melodyPin, keyToNote[s]); 
  delay(100);
  noTone(melodyPin); 
}


//---------- PARSE NOTES TYPED ON WEBSITE ------------- //
void parse(String input){
  char note;
  int playTime;
  bool gotNote = 0;
  bool gotTime = 0;
  int timeTemp[10] = {0};
  
  int str_len = input.length(); 
  
  for (int it = 0; it < str_len; it++) { 
    char c = input.charAt(it);
    
    if (isalpha(c)){ //enter note
      note = c;
      gotNote = 1;
      
    } else if (isdigit(c)){
      playTime = 0;
      int counter = 0;
      
      while (it + counter < str_len){ //scan to get all digits of playtime
        char digit = input.charAt(it+counter);
        if (isDigit(digit)){
          timeTemp[counter] = digit - '0';
          counter++;
        } else {
          break;
        }
      }
      for (int i = 0; i < counter; i++){
         playTime += pow(10, counter-i-1)*timeTemp[i];
      }
      
      it = it + counter-1;
      gotTime = 1;
    } 

    if (gotNote && gotTime){
      InputMakingSound(note, playTime);
      gotNote = 0;
      gotTime = 0;
      
    }
  }
}


//---------- PLAY NOTE FROM WEBSITE ------------- //
void InputMakingSound (char note, int playTime){
  
  short noteDuration = 100 * playTime;
  
  if(note == 'R'){
    delay(noteDuration);
  } else {
    int key = (note - 59)%7; //get note frequency
    int noteFeq = keyToNote[key];
    
    tone(melodyPin, noteFeq);
    LEDinput(note, noteDuration);
    noTone(melodyPin);
  }
}


//---------- PLAY HARDCODED SONGS ------------- //
void sing(short s) {
  // iterate over the notes of the melody:
  if (s == 5){
    Serial.println("Playing");
    String TestInput = "C1D1E1F1G1A1B1";
    parse(TestInput);
  }
  else if (s == 4){
    Serial.println(" '千本樱'");
    short length = sizeof(tune2)/sizeof(tune2[0]);
      for(short x=0;x<length;x++){
        tone(melodyPin,tune2[x]);
        delay(88*durt2[x]);
        noTone(melodyPin);
      }
  }
  else if (s == 3)
  {
    short length = sizeof(tune)/sizeof(tune[0]);
      for(short x=0;x<length;x++){
        short noteDuration = 50 * duration[x];
        buzz(melodyPin, tune[x], noteDuration);
        short pauseBetweenNotes = noteDuration * 1.3;
        LEDsong3(tune[x], pauseBetweenNotes);
        //delay(pauseBetweenNotes);
        buzz(melodyPin, 0, noteDuration);

        
        //tone(melodyPin,tune[x]);
        //LEDsong3(tune[x], 113*duration[x]);
        //delay(113*duration[x]);
        //noTone(melodyPin);
    }
    
  }
  else if (s == 2) {
    Serial.println(" 'Never Gonna Give you up'");
    short size = sizeof(song1_verse1_melody) / sizeof(int);
    for (short thisNote = 0; thisNote < size; thisNote++) {
      short noteDuration = 50 * song1_verse1_rhythmn[thisNote];
      buzz(melodyPin, song1_verse1_melody[thisNote], noteDuration);
      short pauseBetweenNotes = noteDuration * 1.30;
      LEDsong1(song1_verse1_melody[thisNote], pauseBetweenNotes);
      //delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);
    }

  } else if (s == 1){

    Serial.println(" 'Mario Theme'");
    short size = sizeof(melody) / sizeof(int);
    for (short thisNote = 0; thisNote < size; thisNote++) {
      short noteDuration = 1000 / tempo[thisNote];
      buzz(melodyPin, melody[thisNote], noteDuration);
      short pauseBetweenNotes = noteDuration * 1.3;
      LEDsong2(melody[thisNote], pauseBetweenNotes);
      //delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);
    }
  }
}

void buzz(short targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);

}


//---------- LEDS FLASH WITH SONG ------------- //
void LEDsong1(short time, short pause){
  if (time == 523 || time == 554){
    digitalWrite(LED1, HIGH);       //415 466 494 523 554 622 698
    delay(pause);
    digitalWrite(LED1, LOW);
  }
  else if (time == 622){
    digitalWrite(LED3, HIGH);
    delay(pause);
    digitalWrite(LED3, LOW);
  }
  else if (time == 698){
    digitalWrite(LED4, HIGH);
    delay(pause);
    digitalWrite(LED4, LOW);
  }
  else if (time == 415){
    digitalWrite(LED6, HIGH);
    delay(pause);
    digitalWrite(LED6, LOW);
  }
  else if (time == 466 || time == 494){
    digitalWrite(LED7, HIGH);
    delay(pause);
    digitalWrite(LED7, LOW);
  }
  else if (time == 0){
    delay(pause);
  }
}
void LEDsong2(short time, short pause){
  if (time == 2093){
    digitalWrite(LED1, HIGH);
    delay(pause);
    digitalWrite(LED1, LOW);
  }
  else if (time == 2349){
    digitalWrite(LED2, HIGH);
    delay(pause);
    digitalWrite(LED2, LOW);
  }
  else if (time == 2637){
    digitalWrite(LED3, HIGH);
    delay(pause);
    digitalWrite(LED3, LOW);
  }
  else if (time == 2794){
    digitalWrite(LED4, HIGH);
    delay(pause);
    digitalWrite(LED4, LOW);
  }
  else if (time == 1568 || time == 3136){
    digitalWrite(LED5, HIGH);
    delay(pause);
    digitalWrite(LED5, LOW);
  }
  else if (time == 1760 || time == 1865 || time == 3520){
    digitalWrite(LED6, HIGH);
    delay(pause);
    digitalWrite(LED6, LOW);
  }
  else if (time == 1976){
    digitalWrite(LED7, HIGH);
    delay(pause);
    digitalWrite(LED7, LOW);
  }
  else if (time == 0){
    delay(pause);
  }
}
void LEDsong3(short time, short pause){
  if (time == 277 || time == 554 || time == 1109){
    digitalWrite(LED1, HIGH);
    delay(pause);
    digitalWrite(LED1, LOW);
  }
  else if (time == 294 || time == 587 || time == 1175){
    digitalWrite(LED2, HIGH);
    delay(pause);
    digitalWrite(LED2, LOW);
  }
  else if (time == 330 || time == 659 || time == 1319){
    digitalWrite(LED3, HIGH);
    delay(pause);
    digitalWrite(LED3, LOW);
  }
  else if (time == 370 || time == 740 || time == 1480){
    digitalWrite(LED4, HIGH);
    delay(pause);
    digitalWrite(LED4, LOW);
  }
  else if (time == 415 || time == 1661){
    digitalWrite(LED5, HIGH);
    delay(pause);
    digitalWrite(LED5, LOW);
  }
  else if (time == 220 || time == 440 || time == 880){
    digitalWrite(LED6, HIGH);
    delay(pause);
    digitalWrite(LED6, LOW);
  }
  else if (time == 247 || time == 494 || time == 988){
    digitalWrite(LED7, HIGH);
    delay(pause);
    digitalWrite(LED7, LOW);
  }
  else if (time == 0){
    delay(pause);
  }
}
