//Source:  https://www.youtube.com/watch?v=gqAHOoqo3OI&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-&index=13

const String lessonName = "LESSON 13: Controlling an RGB LED with Arduino";
const int baudSpeed = 9600;
const int sleepTime = 1000;
const int shortSleepTime = 500;

const int ledBrightness = 100; //MIN is 0, MAX is 255
const int ledOff = 0; //MIN is 0, MAX is 255
const int ledFullBrightness = 255; //MIN is 0, MAX is 255


//Pins
const int pinBlue = 6;
const int pinGreen = 10;
const int pinRed = 11;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed);
  Serial.println(lessonName);
  setUpPins();
}

void loop() {
  // put your main code here, to run repeatedly:

  testRgb();
}

//Test function - changing RGB colors
void testRgb(){

  //Blue
  turnOnLed("Blue is on", pinBlue, ledBrightness);
  turnOffAllLed();

  //Green
  turnOnLed("Green is on", pinGreen, ledBrightness);
  turnOffAllLed();

  //Red
  turnOnLed("Red is on", pinRed, ledBrightness);
  turnOffAllLed();

  //RGB
  Serial.println("RGB is on");
  turnOnAllLed();
  delay(sleepTime);
  turnOffAllLed();

  //RB
  Serial.println("RB is on");
  turnOnRB();
  delay(sleepTime);
  turnOffAllLed();

  //GB
  Serial.println("GB is on");
  turnOnBG();
  delay(sleepTime);
  turnOffAllLed();

  //RG
  Serial.println("RG is on");
  turnOnRG();
  delay(sleepTime);
  turnOffAllLed();
}

//Turn on LED
void turnOnLed(String logMessage, int pinNumber, int ledBrightness){

  Serial.println(logMessage);
  analogWrite(pinNumber, ledBrightness);
  delay(sleepTime);
}

//Turn off all LEDs
void turnOffAllLed(){

  analogWrite(pinBlue, ledOff);
  analogWrite(pinGreen, ledOff);
  analogWrite(pinRed, ledOff);
}

//Turn off all LEDs
void turnOnAllLed(){

  analogWrite(pinBlue, ledBrightness);
  analogWrite(pinGreen, ledBrightness);
  analogWrite(pinRed, ledBrightness);
}

//Turn on RG
void turnOnRG(){

  analogWrite(pinBlue, 150);
  analogWrite(pinGreen, 0);
  analogWrite(pinRed, 150);
}


//Turn on RB
void turnOnRB(){

  analogWrite(pinBlue, 150);
  analogWrite(pinGreen, 0);
  analogWrite(pinRed, 150);
}

//Turn on BG
void turnOnBG(){

  analogWrite(pinBlue, 150);
  analogWrite(pinGreen, 150);
  analogWrite(pinRed, 0);
}

//Set-up analog pins
void setUpPins(){

  pinMode(pinBlue, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinRed, OUTPUT);
}
