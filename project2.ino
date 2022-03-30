
/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>
#include "pitches.h"
#include <Keypad.h>

#define melodyPin 9
#define LED1 10
#define LED2 11
#define LED3 12
#define LED4 13
#define LED5 A5
#define LED6 A4
#define LED7 A3



//Mario main theme melody
short melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0, 

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0
};
short tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

//Never Gonna Give you up
short song1_verse1_melody[] =
{ NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4,
  NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_DS5, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_AS4,
  NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_CS5,
  NOTE_CS5, NOTE_DS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_DS5, NOTE_CS5,
  NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4,
  NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_GS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4,
  NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_CS5,
  NOTE_CS5, NOTE_DS5, NOTE_C5, NOTE_AS4, NOTE_GS4, 0, NOTE_GS4, NOTE_DS5, NOTE_CS5, 0
};
short song1_verse1_rhythmn[] =
{ 1, 1, 1, 1,
  3, 3, 6, 1, 1, 1, 1, 3, 3, 3, 1, 2,
  1, 1, 1, 1,
  3, 3, 3, 1, 2, 2, 2, 4, 8,
  1, 1, 1, 1,
  3, 3, 6, 1, 1, 1, 1, 3, 3, 3, 1, 2,
  1, 1, 1, 1,
  3, 3, 3, 1, 2, 2, 2, 4, 8, 4
};

//千本樱
short tune2[]=
{
  /*
  NOTE_DS5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_DS5,NOTE_CS5,  //1
  NOTE_DS5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_F5,  //2
  NOTE_DS5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_DS5,NOTE_CS5,  //3
  NOTE_DS5,NOTE_F5,NOTE_G5,NOTE_A5,  //4
  NOTE_G4,NOTE_A4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_G4,NOTE_A4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_C4,  //5
  NOTE_G4,NOTE_A4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_F4,NOTE_E4,NOTE_D4,NOTE_C4,  //6
  NOTE_G4,NOTE_A4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_G4,NOTE_A4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_C4,  //7
  NOTE_G4,NOTE_A4,NOTE_CS5,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_E5,NOTE_DS5,NOTE_CS5,NOTE_A4,  //8
  NOTE_G4,NOTE_A4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_G4,NOTE_A4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_C4,  //9
  NOTE_G4,NOTE_A4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_F4,NOTE_E4,NOTE_D4,NOTE_C4,  //10
  NOTE_F4,NOTE_D4,NOTE_F4,NOTE_G4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_CS5,NOTE_F5,NOTE_A4,NOTE_CS5,  //11
  NOTE_F5,NOTE_E5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_DS5,NOTE_F5,  //12
  NOTE_G5,NOTE_A5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_CS5,NOTE_G5,NOTE_A5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_CS5,  //13
  NOTE_G5,NOTE_A5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_CS5,NOTE_F5,NOTE_E5,NOTE_DS5,NOTE_CS5,  //14
  NOTE_G5,NOTE_A5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_CS5,NOTE_G5,NOTE_A5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_CS5,  //15
  NOTE_G5,NOTE_A5,NOTE_C6,NOTE_FS6,NOTE_E6,NOTE_FS6,NOTE_E6,NOTE_D6,NOTE_C6,NOTE_A5, //16
  NOTE_G5,NOTE_A5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_CS5,NOTE_G5,NOTE_A5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_CS5,  //17
  NOTE_G5,NOTE_A5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_CS5,NOTE_F5,NOTE_E5,NOTE_DS5,NOTE_CS5,  //18
  NOTE_A5,NOTE_G5,NOTE_A5,NOTE_C6,NOTE_D6,NOTE_C6,NOTE_AS5,NOTE_G5,NOTE_DS5,NOTE_F5,NOTE_A5,NOTE_C6,  //19
  NOTE_D6,NOTE_D6,NOTE_C6,NOTE_D6,  //20
  NOTE_DS5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_F5,NOTE_G5,NOTE_A5,  //21
  NOTE_DS5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_CS5,NOTE_A4,NOTE_CS5,  //22
  NOTE_DS5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_F5,NOTE_G5,NOTE_A5,  //23
  NOTE_A5,NOTE_G5,NOTE_F5,NOTE_DS5,  //24
  NOTE_DS5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_F5,NOTE_G5,NOTE_A5,  //25
  NOTE_DS5,NOTE_DS5,NOTE_CS5,NOTE_DS5,NOTE_CS5,NOTE_CS5,NOTE_A4,  //26
  NOTE_DS5,NOTE_DS5,NOTE_CS5,NOTE_CS5,NOTE_DS5,NOTE_F5,NOTE_G5,  //27
  NOTE_A5,NOTE_G5,NOTE_F5,NOTE_DS5,  //28
  NOTE_F5,NOTE_E5,NOTE_DS5,NOTE_CS5,  //29
  NOTE_CS5,NOTE_CS5,NOTE_DS5,NOTE_A4,NOTE_G4,NOTE_A4,  //30
  NOTE_A4,NOTE_CS5,NOTE_DS5,NOTE_G5,NOTE_E5,  //31
  NOTE_F5,NOTE_E5,NOTE_CS5,NOTE_DS5,  //32
  NOTE_F5,NOTE_E5,NOTE_DS5,NOTE_CS5,  //33
  NOTE_CS5,NOTE_CS5,NOTE_DS5,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_CS5,  //34
  NOTE_DS5,NOTE_DS5,NOTE_DS5,NOTE_F5,NOTE_G5,  //35
  NOTE_E5,0  //36
  */
};
short durt2[]=
{
  /*
  2,4,2,2,4,2,  //4
  2,4,2,4,4,  //2
  2,4,2,2,4,2,  //3
  4,4,4,4,  //4
  2,2,1,1,1,1,2,2,1,1,1,1,  //5
  2,2,1,1,1,1,2,2,2,2,  //6
  2,2,1,1,1,1,2,2,1,1,1,1,  //7
  2,2,2,2,1,1,1,1,2,2,  //8
  2,2,1,1,1,1,2,2,1,1,1,1,  //9
  2,2,1,1,1,1,2,2,2,2,  //40
  2,1,1,2,1,1,2,1,1,1,1,1,1,  //44
  2,2,2,2,4,2,2,  //42
  2,2,1,1,1,1,2,2,1,1,1,1,  //43
  2,2,1,1,1,1,2,2,2,2,  //44
  2,2,1,1,1,1,2,2,1,1,1,1,  //45
  2,2,2,2,1,1,1,1,2,2,  //46
  2,2,1,1,1,1,2,2,1,1,1,1,  //47
  2,2,1,1,1,1,2,2,2,2,  //48
  1,1,1,1,1,1,1,1,2,2,2,2,  //49
  2,4,2,4+4,  //20
  4,1+2,1,2,2,2,2,  //24
  4,1+2,1,2,2,2,2,  //22
  4,1+2,1,2,2,2,2,  //23
  4,4,4,4,  //24
  4,1+2,1,2,2,2,2,  //25
  4,1+2,1,2,2,2,2,  //26
  4,1+2,1,2,2,2,2,  //27
  4,4,4,4,  //28
  4,4,4,4,  //29
  2,1,1,2,2,4+4,  //30
  2,2,4,4,4,  //34
  4,2,2,4+4,  //32
  4,4,4,4,  //33
  2,1,1,2,2,4,2,2,  //34
  2,4,2,4,4,  //35
  4+4+4,4+4+4  //36
  */
};

//极乐净土
short tune[] = {
  0,0,0,NOTE_CS5,NOTE_E5,
  NOTE_FS5,0,0,NOTE_E5,NOTE_FS5,0,0,NOTE_E5,
  NOTE_FS5,NOTE_A5,NOTE_E5,NOTE_FS5,NOTE_CS5,0,NOTE_CS5,NOTE_E5,
  NOTE_FS5,0,0,NOTE_E5,NOTE_FS5,0,0,NOTE_E5,
  NOTE_FS5,NOTE_CS6,NOTE_A5,NOTE_B5,NOTE_FS5,0,NOTE_CS5,NOTE_E5,
  NOTE_FS5,0,0,NOTE_E5,NOTE_FS5,0,0,NOTE_E5,
  NOTE_FS5,NOTE_A5,NOTE_E5,NOTE_FS5,NOTE_CS5,NOTE_E5,NOTE_A4,NOTE_B4,
  NOTE_CS5,NOTE_A5,NOTE_FS5,NOTE_CS6,
  NOTE_B5,NOTE_CS6,NOTE_B5,NOTE_A5,NOTE_B5,NOTE_FS5,0,
  NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_A5,NOTE_B5,NOTE_CS6,
  NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_E5,NOTE_E5,NOTE_FS5,
  NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_A5,NOTE_B5,NOTE_CS6,
  NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_D6,NOTE_D6,NOTE_CS6,
  NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_A5,NOTE_B5,NOTE_CS6,
  NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_E5,NOTE_E5,NOTE_FS5,
  NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_FS5,NOTE_A5,NOTE_B5,NOTE_CS6,
  NOTE_FS6,NOTE_E5,NOTE_E5,NOTE_FS5,NOTE_FS5
};
short duration[]= {
  4,4,4,2,2,
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,2,2,2,
  2,2,2,2,2,2,2,2,
  4,4,4,4,
  2,1,1,2,2,4,4,
  4,4,4,1,1,1,1,
  4,4,2,2,2,2,
  4,4,4,1,1,1,1,
  4,4,2,2,2,2,
  4,4,4,1,1,1,1,
  4,4,2,2,2,2,
  4,4,4,1,1,1,1,
  4+2,2,2,2,4
};

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

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

short pos = 0;    // variable to store the servo position

void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
}

String val;
int InputOrNot = 0;

short CurrentStatus = 0; // To indicate the status is tone mode or music mode

void loop() {
  char customKey = customKeypad.getKey();

  //The Part Which relate to the SERVER//
  if (Serial.available() > 0) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
    InputOrNot = 1;
  }

  Serial.print(val);
  if (InputOrNot == 1){
    parse(val);
    InputOrNot == 0;
  }
  //////////////////////////////////////
  

  if (customKey == '*')
  {
    if (CurrentStatus == 0)
    {
      CurrentStatus = 1;
      Serial.println("Status Change");
    }
    else
    {
      CurrentStatus = 0;
      Serial.println("Status Change");
    }
  }
  
  if (CurrentStatus == 0)
  {
    if (customKey == '1')
    {
      sing(1);
    }
    else if (customKey == '2')
    {
      sing(2); 
    }
    else if (customKey == '3')
    {
      sing(3);
    }
    else if (customKey == '4')
    {
      sing(4);
    }
    else if (customKey == '5')
    {
      sing(5);
    }
  }
  else
  {
    if (customKey == '1')
    {
      digitalWrite(LED1, HIGH);
      ToneTone(1);
      delay(50);
      digitalWrite(LED1, LOW);
    }
    else if (customKey == '2')
    {
      digitalWrite(LED2, HIGH);
      ToneTone(2); 
      delay(50);
      digitalWrite(LED2, LOW);
    }
    else if (customKey == '3')
    {
      digitalWrite(LED3, HIGH);
      ToneTone(3); 
      delay(50);
      digitalWrite(LED3, LOW);
    }
    else if (customKey == '4')
    {
      digitalWrite(LED4, HIGH);
      ToneTone(4); 
      delay(50);
      digitalWrite(LED4, LOW);
    }
    else if (customKey == '5')
    {
      digitalWrite(LED5, HIGH);
      ToneTone(5); 
      delay(50);
      digitalWrite(LED5, LOW);
    }
    else if (customKey == '6')
    {
      digitalWrite(LED6, HIGH);
      ToneTone(6); 
      delay(50);
      digitalWrite(LED6, LOW);
    }
    else if (customKey == '7')
    {
      digitalWrite(LED7, HIGH);
      ToneTone(7); 
      delay(50);
      digitalWrite(LED7, LOW);
    }
  }
}

short song = 0;
void LEDsong1(short time, short pause){
  if (time == 523 || time == 554){
    digitalWrite(LED1, HIGH);       //415 466 494 523 554 622 698
    delay(pause);
    digitalWrite(LED1, LOW);
  }
  /*else if (time == 466){
    digitalWrite(LED2, HIGH);
    delay(pause);
    digitalWrite(LED2, LOW);
  }*/
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
  /*else if (time == 554){
    digitalWrite(LED5, HIGH);
    delay(pause);
    digitalWrite(LED5, LOW);
  }*/
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

void LEDinput(char note, short pause){
  if (note == 'C' || note == 'c'){
    digitalWrite(LED1, HIGH);
    delay(pause);
    digitalWrite(LED1, LOW);
  }
  else if (note == 'D' || note == 'd'){
    digitalWrite(LED2, HIGH);
    delay(pause);
    digitalWrite(LED2, LOW);
  }
  else if (note == 'E' || note == 'e'){
    digitalWrite(LED3, HIGH);
    delay(pause);
    digitalWrite(LED3, LOW);
  }
  else if (note == 'F' || note == 'f'){
    digitalWrite(LED4, HIGH);
    delay(pause);
    digitalWrite(LED4, LOW);
  }
  else if (note == 'G' || note == 'g'){
    digitalWrite(LED5, HIGH);
    delay(pause);
    digitalWrite(LED5, LOW);
  }
  else if (note == 'A' || note == 'a'){
    digitalWrite(LED6, HIGH);
    delay(pause);
    digitalWrite(LED6, LOW);
  }
  else if (note == 'B' || note == 'b'){
    digitalWrite(LED7, HIGH);
    delay(pause);
    digitalWrite(LED7, LOW);
  }
  else if (note == 'R' || note == 'r'){
    delay(pause);
  }
}

void ToneTone(short s){
  if (s == 1)
  {
    tone(melodyPin, 262);
    delay(100);
    noTone(melodyPin);
  }
  else if (s == 2)
  {
    tone(melodyPin, 294);
    delay(100);
    noTone(melodyPin);
  }
  else if (s == 3)
  {
    tone(melodyPin, 330);
    delay(100);
    noTone(melodyPin);
  }
  else if (s == 4)
  {
    tone(melodyPin, 350);
    delay(100);
    noTone(melodyPin);
  }
  else if (s == 5)
  {
    tone(melodyPin, 392);
    delay(100);
    noTone(melodyPin);
  }
  else if (s == 6)
  {
    tone(melodyPin, 440);
    delay(100);
    noTone(melodyPin);
  }
  else if (s == 7)
  {
    tone(melodyPin, 494);
    delay(100);
    noTone(melodyPin);
  }
}

void parse(String input){

  bool readNote = 1;
  char note;
  int playTime;
  int TimeTemp[10];
  int counter;
  int noteReadyorNot = 0;
  
  int str_len = input.length(); 
  char char_array[str_len+1];

  input.toCharArray(char_array, str_len+1);
  
  for (int it = 0; it < str_len; it++) { 
    //skip first three letters play mode, button
    
    if (isalpha(char_array[it])){ //enter note
      note = char_array[it];
      noteReadyorNot = 1;
    } 
    else if (isdigit(char_array[it])){
      counter = 0;
      while (it + counter < str_len){
        if (isalpha(char_array[it+counter]) == false){
          if (counter > 9){
            counter++;
          }
          else {
          TimeTemp[counter] = char_array[it+counter] - '0';
          counter++;
          }
        }
        else{
          break;
        }
      }
      playTime = 0;
      int exponent = counter-1;
      for (int i = 0 ; i <= exponent; i++)
      {
        playTime = playTime + TimeTemp[i]*(pow(10, exponent));
        exponent--;
      }
      it = it + counter-1;
      if (noteReadyorNot == 1)
      {
        InputMakingSound(note, playTime);
        noteReadyorNot = 0;
      }
    } 
    else {
      Serial.println("ERROR");
      //print error of some sort
    }
  }
}

void InputMakingSound (char note, int playTime){
  int noteFeq;

  if (note == 'C' || note == 'c'){
    noteFeq = 262;
  } else if (note == 'D' || note == 'd'){
    noteFeq = 294;
  } else if (note == 'E' || note == 'e'){
    noteFeq = 330;
  } else if (note == 'F' || note == 'f'){
    noteFeq = 350;
  } else if (note == 'G' || note == 'g'){
    noteFeq = 392;
  } else if (note == 'A' || note == 'a'){
    noteFeq = 440;
  } else if (note == 'B' || note == 'b'){
    noteFeq = 494;
  } else if (note == 'R' || note == 'r'){
    noteFeq = -1;
  }
  short noteDuration = 100 * playTime;
  tone(melodyPin, noteFeq);
  short pauseBetweenNotes = noteDuration;
  LEDinput(note, pauseBetweenNotes);
  delay(100);
  noTone(melodyPin);
}

void sing(short s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 5){
    Serial.println("Playing");
    String TestInput = "C1D1E1F1G1A1B1";
    parse(TestInput);
  }
  else if (song == 4){
    Serial.println(" '千本樱'");
    short length = sizeof(tune2)/sizeof(tune2[0]);
      for(short x=0;x<length;x++){
        tone(melodyPin,tune2[x]);
        delay(88*durt2[x]);
        noTone(melodyPin);
      }
  }
  else if (song == 3)
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
  else if (song == 2) {
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

  } else if (song == 1){

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
