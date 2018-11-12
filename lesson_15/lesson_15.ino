//Source: https://www.youtube.com/watch?v=Ltp3skGLqFM&index=16&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-

const int baudSpeed = 9600;
const int waitTime = 25; //Wait time in ms
const int longWaitTime = 500; 

const String lessonName = "LESSON 15: Super Cool Arduino Color Sensor Project";
const int pinRed = 11;
const int pinGreen = 10;
const int pinBlue = 6;

const int ledBrightness = 120;

const int pinOUT = 4;
const int pinS2 = 7;
const int pinS3 = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudSpeed);
  Serial.println(lessonName);
}

void loop() {
  // put your main code here, to run repeatedly:
  turnOffLed();
  testLed();
}


//Turn off all colors
void turnOffLed(){
  
  //Turn off all colors
  analogWrite(pinRed, 0);
  analogWrite(pinGreen, 0);
  analogWrite(pinBlue, 0);
}


//Test LED
void testLed(){

  //Red
  analogWrite(pinRed, ledBrightness);
  delay(longWaitTime);
  turnOffLed();

  //Green
  analogWrite(pinGreen, ledBrightness);
  delay(longWaitTime);
  turnOffLed();

  //Blue
  analogWrite(pinBlue, ledBrightness);
  delay(longWaitTime);
  turnOffLed();
}
