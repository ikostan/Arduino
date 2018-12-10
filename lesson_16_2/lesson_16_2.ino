//LESSON 16: Controlling a Servo with Arduino
//Source: https://www.youtube.com/watch?v=fE4m7TyLd8M&index=17&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-servo

#include <Servo.h>

#define lessonName "LESSON 16: Controlling a Servo with Arduino"
#define servoPin 9
#define potentiometerPin A0
#define baudSpeed 9600
#define delayTime 35

#define servoStart 35
#define servoStop 160

#define potMin 0
#define potMax 1023

#define buffValue 3

int potPosition = 0; //Min = 0, Max = 1023
int servoPosition = servoStart;
int servoOldPosition = servoStart;
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

  /*
  potPosition = 0 => servoPosition = servoStart
  potPosition = 1023 => servoPosition = servoStop
  */
  potPosition = analogRead(potentiometerPin); //Reading potentiometer
  //Serial.println(String(potPosition)); //Log

  servoPosition = ((160. - 35.) / (1023. - 0)) * potPosition + 35;
  Serial.println(String(servoPosition)); //Log

  if(servoOldPosition != servoPosition + buffValue || servoOldPosition != servoPosition - buffValue){

    servoObj.write(servoPosition);
    servoOldPosition = servoPosition;
  }
  
  //testServo();
  delay(delayTime);
}

void testServo(){
  
  for(servoPosition = servoStart; servoPosition <= servoStop; servoPosition = servoPosition + 1){
    
    servoObj.write(servoPosition);
    delay(delayTime);
    }  

  for(servoPosition = servoStop; servoPosition >= servoStart; servoPosition = servoPosition - 1){
    
    servoObj.write(servoPosition);
    delay(delayTime);
    }  
}
