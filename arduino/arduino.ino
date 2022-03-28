
 // Read data from the serial and turn ON or OFF a light depending on the value
 
 char val; // Data received from the serial port
 int ledPin = 8; 
 
 void setup() {
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  Serial.begin(9600); // Start serial communication at 9600 bps
 }
 
 void loop() {
  while (Serial.available()) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
  }
  Serial.print(val);

  //return string with play mod 0/1 | button pressed 01-10 | text box answer
//  if (val[0] == "type") { // If text box mode
//    parse(val);
//    digitalWrite(ledPin, HIGH); // turn the LED on
//  } else {
//    digitalWrite(ledPin, LOW); // Otherwise turn it OFF
//  }
  delay(100); // Wait 100 milliseconds for next reading
 }

 void parse(String val){

  bool readNote = 1;
  char note;
  int playTime;
  
  for (auto it = val.begin() + 3; it < val.end(); it++) { 
    //skip first three letters play mode, button
    
    if (note == 1 && isalpha(*it)){ //enter note
      note = *it;
    } else if (note == -1 && isdigit(*it)){
      playTime = int(*it);
    } else {
      //print error of some sort
    }

    if(readNote == -1){
      //play note 
      delay(playTime*1000); //play for playTime seconds
    }
    
    note *= -1;
  }
    
 }
 
