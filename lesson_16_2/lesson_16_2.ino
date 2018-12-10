//LESSON 16: Controlling a Servo with Arduino
//Source: https://www.youtube.com/watch?v=fE4m7TyLd8M&index=17&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-servo

#include <Servo.h>

#define lessonName "LESSON 16: Controlling a Servo with Arduino"
#define servoPin 9
#define potentiometerPin A0
#define baudSpeed 9600
#define delayTime 25

#define servoStart 15
#define servoStop 170

int potPosition = 0; //Min = 0, Max = 1023
int servoPosition = 0;
Servo servoObj; //Servo object

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  Serial.println(lessonName);
  pinMode(potentiometerPin, INPUT);
  servoObj.attach(servoPin);
  servoObj.write(servoStart);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //potPosition = analogRead(potentiometerPin); //Reading potentiometer
  //Serial.println(String(potPosition));
  
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
