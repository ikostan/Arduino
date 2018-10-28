// Ohm law: V=I*R (V - voltage in volts, R - resistance in Ohms, I - current in Amps)
// On the arduino uno you can do analog writes on pins: 3,5,6,9,10,11.
// Voltage equation calculation: V * 51, where 0 is 0V and 255 is 5V.
// Source: https://www.youtube.com/watch?v=J7t338s6l1I&index=9&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-

const float baudSpeed = 115200;
const int redPin = 11;
const int greenPin = 12;
const int sleepTime = 50;
const int voltToAnalog = 51;

const String tutorialName = "Lesson #9: Ohm's Law and Potentiometers with Arduino.";
const String redOn = "Red LED is on";
const String redOff = "Red LED is off";
const String greenOn = "Green LED is on";
const String greenOff = "Green LED is off";

void setup() {
  // put your setup code here, to run once:
  boardSetup(baudSpeed, tutorialName, redPin, greenPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenPin, HIGH);
}

// Setup Arduino board: set pins and serial baud speed
void boardSetup(float baudSpeed, String tutorialName, int redPin, int greenPin){
  
  Serial.begin(baudSpeed);
  Serial.println(tutorialName);
  pinMode(redPin, OUTPUT);
  Serial.println("Red LED is on pin " + String(redPin));
  pinMode(greenPin, OUTPUT);
  Serial.println("Green LED is on pin " + String(greenPin));
}
