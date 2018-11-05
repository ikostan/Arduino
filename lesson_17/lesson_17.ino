//Source:  https://www.youtube.com/watch?v=eaHRHQ5Ca_U&index=18&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-

const String lessonName = "LESSON 17: Measure Speed of Sound with Arduino and Ultrasonic Sensor";
const int baudSpeed = 9600;
const int waitTime = 25; //Wait time in ms

//Pins
const int echoPin = 11;
const int trigerPin = 13;
const int sleepTime = 2000;

//Variables
int pingTime; //Time for ping to get target end return
float speedOfSound; //Speed of sound calculation
float targetDistance = 1.97; //Distance in inch

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudSpeed);
  Serial.println(lessonName);
  pinMode(echoPin, INPUT);
  pinMode(trigerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Send a signal
  digitalWrite(trigerPin, LOW); //Set a triger ping LOW
  delayMicroseconds(2000); //WAIT
  digitalWrite(trigerPin, HIGH); //Send a triger ping HIGH
  delayMicroseconds(10); //WAIT
  digitalWrite(trigerPin, LOW); //Set a triger ping LOW

  //Mesure a time for ping to come back
  pingTime = pulseIn(echoPin, HIGH);
}
