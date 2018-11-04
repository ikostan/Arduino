//Source:  https://www.youtube.com/watch?v=fE4m7TyLd8M

#include <Servo.h> //Loading the servo library

const String lessonName = "LESSON 16: Controlling a Servo with Arduino";
const int baudSpeed = 9600;
const int waitTime = 25; //Wait time in ms
const float convertionRate = 204.6; // 1023 devided by 5

//Pins
const int servoControlPin = 9; //Servo controlling pin
const int potentiometerAnalogPin = A0; //Potentiometer reading pin

//Logs
const String turnLeft = "<--";
const String turnRight = "-->";
const String potentiometerValue = "Potentiometer: ";
const String voltageValue = "Voltage: ";

//Variables
int currentRate; //Potentiometer is reading the voltage between 0 and 1023.
float voltage;
int servoPosition = 0; //Servo position variable

//Setup
void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed); //Sets the data rate in bits per second (baud) for serial data transmission
  Serial.println(lessonName);
  pinMode(potentiometerAnalogPin, INPUT); // Set analog pin A0 for potentiometer
  pinMode(servoControlPin, OUTPUT); // set digital pin 9 for servo
}

//Main loop
void loop() {
  // put your main code here, to run repeatedly:

  currentRate = analogRead(potentiometerAnalogPin); //Reading from potentiometer
  voltage = currentRate / convertionRate; //Convert input from potentiometer in to VOLTS
  Serial.println(potentiometerValue + String(currentRate) + ". " + voltageValue + String(voltage) + "."); //Logs
  delay(waitTime); //Delay
}
