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
int pingTime; //Time for ping to get target end return
float speedOfSound; //Speed of sound calculation
float targetDistance = 1.97; //Distance in inch

void setup() {

  Serial.begin(baudSpeed);
  Serial.println(lessonName);
}

void loop() {
  
}
