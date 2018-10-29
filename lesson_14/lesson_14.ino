//Source:  https://www.youtube.com/watch?v=J43xw4WXnx8&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-&index=14

const String lessonName = "LESSON 14: Arduino If Statements and Conditionals";
const int baudSpeed = 9600;
const int sleepTime = 1000;
const int shortSleepTime = 500;
const String askForColor = "\nPlease enter the color ('R' for red, 'G' for green, 'B' for blue, '0' to turn off):";
const String invalidInput = "\nERROR: invalid input. Please re-enter.";

const int ledBrightness = 100; //MIN is 0, MAX is 255
const int ledOff = 0; //MIN is 0, MAX is 255
const int ledFullBrightness = 255; //MIN is 0, MAX is 255


//Pins
const int pinBlue = 6;
const int pinGreen = 10;
const int pinRed = 11;

//User input
String userInput;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed);
  Serial.println(lessonName);
  setUpPins();
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(askForColor);

  while(Serial.available() == 0){
    //Do nothing and wait for user input  
  }

  userInput = Serial.readString();
  userInput.trim();

  if(userInput.equals("R") || userInput.equals("r")){
    //RED
    turnOffAllLed();
    turnOnLed("Red is on", pinRed, ledBrightness);
  }
  else if(userInput.equals("G") || userInput.equals("g")){
    //GREEN
    turnOffAllLed();
    turnOnLed("Green is on", pinGreen, ledBrightness);
  }
  else if(userInput.equals("B") || userInput.equals("b")){
    //BLUE
    turnOffAllLed();
    turnOnLed("Blue is on", pinBlue, ledBrightness);
  }
  else if(userInput.equals("0")){
    //BLUE
    turnOffAllLed();
  }
  else{
    //Error
    Serial.println(invalidInput);
  }
}

//Turn on LED
void turnOnLed(String logMessage, int pinNumber, int ledBrightness){

  Serial.println(logMessage);
  analogWrite(pinNumber, ledBrightness);
  //delay(sleepTime);
}

//Turn off all LEDs
void turnOffAllLed(){

  analogWrite(pinBlue, ledOff);
  analogWrite(pinGreen, ledOff);
  analogWrite(pinRed, ledOff);
}

//Set-up analog pins
void setUpPins(){

  pinMode(pinBlue, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinRed, OUTPUT);
}
