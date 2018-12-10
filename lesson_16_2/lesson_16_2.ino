//LESSON 16: Controlling a Servo with Arduino
//Source: https://www.youtube.com/watch?v=fE4m7TyLd8M&index=17&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-servo

#include <Servo.h>

#define lessonName "LESSON 16: Controlling a Servo with Arduino"
#define servoPin 9
#define potentiometerPin A0
#define baudSpeed 9600
#define delayTime 25

int potPosition = 0; //Min = 0, Max = 1023
Servo servoObj; //Servo object

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  Serial.println(lessonName);
  pinMode(potentiometerPin, INPUT);
  servoObj.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  potPosition = analogRead(potentiometerPin);
  Serial.println(String(potPosition));

  delay(delayTime);
}
