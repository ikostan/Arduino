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
  servoObj.write(160);
  delay(700);
  servoObj.write(30);

  //Set up pins
  pinMode(servoPin, OUTPUT);
  pinMode(trigerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  //Triger echo sensor
  digitalWrite(trigerPin, LOW);
  delayMicroseconds(2000);
  digitalWrite(trigerPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigerPin, LOW);

  //Mesure ping time in microseconds
  pingTime = pulseIn(echoPin, HIGH);
  pingTime = pingTime / 1000000.0; //Convert to seconds
  pingTime = pingTime / 3600.0; //Convert to hours

  //Calculate distanse to target in miles
  targetDistance = speedOfSound * pingTime;
  targetDistance = targetDistance / 2.; //Divide by 2 since ping goes back and forward
  targetDistance = targetDistance * 63360; //Convert to inches

  Serial.println("The distance to target is " + String(targetDistance) + " inch"); //log
  delay(1000);
}
