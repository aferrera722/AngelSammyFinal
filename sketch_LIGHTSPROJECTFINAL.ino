
String inString = "0"; // string, int, and multiple hexa
int red1_light_pin=9;
int green1_light_pin = 10;
int blue1_light_pin = 11;
int red2_light_pin = 6;
int green2_light_pin = 5;
int blue2_light_pin = 4;
void setup() 
{
  Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(13, OUTPUT);


  
  pinMode(red1_light_pin, OUTPUT);
  pinMode(green1_light_pin, OUTPUT);
  pinMode(blue1_light_pin, OUTPUT);
    pinMode(red2_light_pin, OUTPUT);
  pinMode(green2_light_pin, OUTPUT);
  pinMode(blue2_light_pin, OUTPUT);
}
void loop() {
  receiveString();
  
    if (inString == "1"){         //whatever conditional / logic / mapping
   RGB_color(255, 0, 0); // Red 
  }
  else if (inString =="2"){
    RGB_color(0, 255, 0); // green
  }
  else if (inString =="3"){
    RGB_color(255,255,0); // yellow
  }
  else if (inString =="4"){
    RGB_color(0,174,50); //
  }
//  RGB_color(255, 0, 0); // Red
//
//  RGB_color(0, 255, 0); // Green
//
//  RGB_color(0, 0, 255); // Blue
//
//  RGB_color(255, 255, 125); // Raspberry
//  
//  RGB_color(0, 255, 255); // Cyan
//  
//  RGB_color(255, 0, 255); // Magenta
//  
//  RGB_color(255, 255, 0); // Yellow
  
  //RGB_color(0, 0, 255); // White
  
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red1_light_pin, red_light_value);
  analogWrite(green1_light_pin, green_light_value);
  analogWrite(blue1_light_pin, blue_light_value);

    analogWrite(red2_light_pin, red_light_value);
  analogWrite(green2_light_pin, green_light_value);
  analogWrite(blue2_light_pin, blue_light_value);
}

void receiveString(){ //needs teriminal new line to end packet (or a character of your choosing in processing)
  inString = Serial.readStringUntil('\n');
  inString.trim();

}
