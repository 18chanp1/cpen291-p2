import http.requests.*;
import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

void setup() 
{
  size(400,400);
  smooth();
  //printArray(Serial.list());
  String portName = Serial.list()[3];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  delay(500);
  GetRequest get = new GetRequest("https://arduinowifi.van1011.repl.co/light");
  get.send();
  String content = get.getContent();
  println("Reponse Content: " + content);
  boolean on = content.equals("on");
  if (on) {  
    println("should on");
    fill(204);                    // change color and
    myPort.write('H');              // send an H to indicate mouse is over square
  } 
  else {                        
    fill(0);                      // change color and
    myPort.write('L');              // send an L otherwise
  }
  rect(50, 50, 100, 100);         // Draw a square
}
