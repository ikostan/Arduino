//On the arduino uno you can do analog writes on pins 3,5,6,9,10,11
//Voltage => 0-255, where 0 is 0V and 255 is 5v. 1V => 51. 

const float baudSpeed = 115200;
const int redPin = 11;
const int greenPin = 12;
const int sleepTime = 50;
const int voltToAnalog = 51;

const String tutorialName = "Lesson #8: Write analog voltages on the Arduino.";
const String redOn = "Red LED is on";
const String redOff = "Red LED is off";
const String greenOn = "Green LED is on";
const String greenOff = "Green LED is off";

void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.println(tutorialName);
}

void loop() {
  // put your main code here, to run repeatedly:

  //testLed();
  for(float i=0; i<=5; i=i+0.1){

    writeVoltage(i, redPin);
    delay(sleepTime);
  }

  for(float j=5; j>=0; j=j-0.1){

    writeVoltage(j, redPin);
    delay(sleepTime);
  }
}

//Analog function => write different voltage
void writeVoltage(float voltage, int pinNum){

  int units = voltage * voltToAnalog;
  analogWrite(pinNum, units);  
  Serial.println("Writing " + String(voltage) + " volts, witch is " + String(units) + " units.");
}

//Test functioin
void testLed(){
  
  turnLedOn(redPin, sleepTime, redOn);
  turnLedOff(redPin, sleepTime, redOff);
  turnLedOn(greenPin, sleepTime, greenOn);
  turnLedOff(greenPin, sleepTime, greenOff);
}

//Turn LED ON
void turnLedOn(int pinNum, int waitTime, String logMsg){

  digitalWrite(pinNum, HIGH);
  Serial.println(logMsg);
  delay(waitTime);
}

//Turn LED OFF
void turnLedOff(int pinNum, int waitTime, String logMsg){

  digitalWrite(pinNum, LOW);
  Serial.println(logMsg);
  delay(waitTime);
}
  
