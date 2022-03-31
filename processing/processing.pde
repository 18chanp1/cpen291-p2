import http.requests.*;
import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port
String lastContent = "";
String currToggle = "online";

void setup(){
  size(400,400);
  smooth();
  String portName = Serial.list()[3];
  myPort = new Serial(this, portName, 9600);
  PostRequest post = new PostRequest("http://cpen291-20.ece.ubc.ca/api/status/");
  post.addData("free");
  post.send();
  
}

void draw() {
  
  //Get play mode (online or arduino) from server
  GetRequest toggleMode = new GetRequest("http://cpen291-20.ece.ubc.ca/api/toggle");
  toggleMode.send();
  String newToggle = toggleMode.getContent();
  
  if(!newToggle.equals(currToggle)){ //check that the toggle has been switched
    if(newToggle.equals("online")){
      myPort.write("S");
      println("switched to online");
    } else {
      myPort.write("H");
      println("switched to hardware");
    }

    currToggle = newToggle;
  }
  
  if (currToggle.equals("online")){ //online control mode
    GetRequest get = new GetRequest("http://cpen291-20.ece.ubc.ca/api/input");
    get.send();
    String content = get.getContent();
    
    if(!content.equals(lastContent)){  //get stream of notes from arduino 
      println("Reponse Content: " + content);
      lastContent = content;
      if(content.equals("Mario")){
        myPort.write("M");
      } else if(content.equals("RickRoll")){
        myPort.write("R");
      } else if (content.equals("GoukurakuJoudo")){
        myPort.write("G");
      } else {
        myPort.write(content);
      }
    }
    
    while(myPort.available() > 0){ //get response from arduino
      int playStatus = myPort.read();
      
      if(playStatus == 36){ //$ sent by arduino to indicate state change
        PostRequest post = new PostRequest("http://cpen291-20.ece.ubc.ca/api/status/");
        post.addData("playing");
        post.send();
        
      } else if (playStatus == 37) {
        PostRequest post = new PostRequest("http://cpen291-20.ece.ubc.ca/api/status/");
        post.addData("free");
        post.send();
      } 
    }
  } 
  
  rect(50, 50, 100, 100);         // Draw a square
}
