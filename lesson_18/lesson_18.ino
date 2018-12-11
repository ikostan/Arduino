#include <Servo.h>

//Source:  https://www.youtube.com/watch?v=rTM5gZxBPmY&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-&index=19

#define lessonName "Lesson 18: Measure Distance with Arduino and Ultrasonic Sensor"
#define  baudSpeed 9600
#define  waitTime 25 //Wait time in ms

//Pins
#define potPin A0
#define servoPin 9
#define echoPin 11
#define trigerPin 13

//Variables
float pingTime; //Time for ping to get target end return
float speedOfSound = 776.5; //Speed of sound in miles per hour
float targetDistance; //Distance to a target
float servoAngle;

Servo servoObj;


void setup() {

  //Start serial monitor
  Serial.begin(baudSpeed);
  Serial.println(lessonName);

  //Set up servo
  servoObj.attach(servoPin);
  servoObj.write(30);

  //Set up pins
  pinMode(servoPin, OUTPUT);
  pinMode(trigerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
}
