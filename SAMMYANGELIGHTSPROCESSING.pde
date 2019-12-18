//byte outByte = byte(255); // single byte (replaced by data)
//int[] outVarsArray = {238, 0}; //multiple variables (replaced by data)
//String outHexArray[] = new String[outVarsArray.length]; //multpiple variables
//String outVars;
int outInt = 1023; //int
//String outString = "OFF"; //string




import processing.serial.*;


Serial myPort; 




import processing.sound.*;

SoundFile[] file;

// Define the number of samples 
int numsounds = 5;

// Define a variable to store the randomly generated background color in
int backgroundColor[] = {255, 255, 255};

void setup() {
  size(640, 360);
  
   println(Serial.list()); //print serial devices (remember to count from 0)
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600); //make sure the baudrate matches arduino

  // Create a Sound renderer and an array of empty soundfiles
  file = new SoundFile[numsounds];

  // Load 5 soundfiles from a folder in a for loop. By naming
  // the files 1.aif, 2.aif, 3.aif, ..., n.aif it is easy to iterate
  // through the folder and load all files in one line of code.
  for (int i = 0; i < numsounds; i++) {
    file[i] = new SoundFile(this, (i+1) + ".aif");
  }
}

void draw() {
  background(backgroundColor[0], backgroundColor[1], backgroundColor[2]);
  myPort.write(str(outInt) + '\n');
  println(outInt);
}


void keyPressed() {
  // We use a boolean helper variable to determine whether one of the branches
  // of the switch-statement was activated or not
  boolean validKey = true;

  switch(key) {
  case 'a':
    file[0].play(3.0, 1.0);
    outInt = 1;
    break;

  case 'd':
    file[1].play(0.5, 1.0);
    outInt = 2;
    break;

  case 'h':
    file[2].play(2.0, 2.0);
    outInt = 3;
    break;

  case 'l':
    file[3].play(3.0, 2.0);
    outInt = 4;
    break;

 

    // no valid key was pressed, store that information
  default:
    validKey = false;
  }

  // If a new sample playback was triggered, change the background color
  if (validKey) {
    for (int i = 0; i < 3; i++) {
      backgroundColor[i] = int(random(255));
    }
  }
}
