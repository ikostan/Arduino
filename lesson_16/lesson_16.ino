//Source:  https://www.youtube.com/watch?v=fE4m7TyLd8M

#include <Servo.h> //Loading the servo library

const String lessonName = "LESSON 16: Controlling a Servo with Arduino";
const int baudSpeed = 9600;
const int waitTime = 25; //Wait time in ms
const float convertionRateToVolts = 204.6; // 1023 devided by 5
const float convertionRate = 5.68; // 1023 devided by 180

//Pins
const int servoControlPin = 9; //Servo controlling pin
const int potentiometerAnalogPin = A0; //Potentiometer reading pin

//Logs
const String turnLeft = "<--";
const String turnRight = "-->";
const String potentiometerValue = "Potentiometer: ";
const String voltageValue = "Voltage: ";

//MIN and MAX values for the servo
//MIN and MAX are safe values for servo. PLEASE NOTE that each servo has different min and max values.
const int minTurn = 45;
const int maxTurn = 180;
const int turnSpeed = 2;

const String askForServoPosition = "Please enter a servo position:"; 
String validValues = "Min: " + String(minTurn) + " Max: " + String(maxTurn);
const String invalidInput = "ERROR: invalid input. Pleaase reenter.";

//Variables
int currentRate; //Potentiometer is reading the voltage between 0 and 1023.
int previousCurrentRate = 0; 
float voltage;
String prePosition;
int previousServoPosition = 0; //previous servo position
int servoPosition = 0; //Servo position variable

//Ojects
Servo servoObj; //Servo object

//Setup
void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed); //Sets the data rate in bits per second (baud) for serial data transmission
  Serial.println(lessonName); //Log

  servoObj.attach(servoControlPin); //Attaching servo to pin 9
  
  pinMode(potentiometerAnalogPin, INPUT); // Set analog pin A0 for potentiometer
  //pinMode(servoControlPin, OUTPUT); // set digital pin 9 for servo
}

//Main loop
void loop() {
  // put your main code here, to run repeatedly:

  

  /*
  loopingServo();
  */

  /*
  manualControl();
  */
  

  currentRate = analogRead(potentiometerAnalogPin); //Reading from potentiometer
  //voltage = currentRate / convertionRateToVolts; //Convert input from potentiometer in to VOLTS
  //Serial.println(potentiometerValue + String(currentRate) + ". " + voltageValue + String(voltage) + "."); //Logs
  
  //Main reason is to make servo is more stable, filters voltagejumps
  if(currentRate == (previousCurrentRate + 1) || 
      currentRate == (previousCurrentRate - 1) || 
      currentRate == previousCurrentRate){
    
    //Do nothing
    Serial.println("Filter is ON"); //Logs
  }
  else{

    //CHANGE SERVO POSITION
    previousCurrentRate = currentRate;
    potentiometerControl(currentRate);
  }
  
  delay(waitTime); //Delay
}

//Turn servo from Min to Max and vice versa
void loopingServo(){

  //UP
  for(servoPosition = minTurn; servoPosition <= maxTurn; servoPosition = servoPosition + turnSpeed){

    if(servoPosition >= minTurn && servoPosition <= maxTurn){

      //Set servo position
      Serial.println(turnRight);
      servoObj.write(servoPosition);
     }
     else{
      //Error
      Serial.println(invalidInput);
     }

     delay(waitTime); //Delay
   }

   //DOWN
   for(servoPosition = maxTurn; servoPosition >= minTurn; servoPosition = servoPosition - turnSpeed){

    //Set servo position
    if(servoPosition >= minTurn && servoPosition <= maxTurn){

      //Set servo position
      Serial.println(turnLeft);
      servoObj.write(servoPosition);
     }
     else{
      //Error
      Serial.println(invalidInput);
     }

     delay(waitTime); //Delay
   }
}

//Control servo manualy
void manualControl(){

  //Prompt the user
  Serial.println(askForServoPosition);
  Serial.println(validValues);

  //Wait for user input
  while(Serial.available() == 0){
    //Do nothing
    }

  //Get servo position
  prePosition = Serial.readString();
  prePosition.trim();
  //servoPosition = Serial.parseInt();
  servoPosition = prePosition.toInt();
  Serial.println("servoPosition: " + String(servoPosition));

  //Set servo position
  if(servoPosition >= minTurn && servoPosition <= maxTurn){
    
    servoObj.write(servoPosition);
   }
   else{

    Serial.println(invalidInput);
   }

  delay(waitTime); //Delay
}

//Control servo manualy
void potentiometerControl(int currentRate){

  //Get servo position
  servoPosition = currentRate / convertionRate;
  //Serial.println("servoPosition: " + String(servoPosition));

  //Set servo position
  if(servoPosition >= minTurn && servoPosition <= maxTurn){

    //Log:
    if(previousServoPosition > servoPosition){

      //Down
      Serial.println(turnLeft);
    }
    else if(previousServoPosition < servoPosition){

      //Up
      Serial.println(turnRight);
    }
    else{

      //No movement
      Serial.println();
    }
        
    //Set servo position
    servoObj.write(servoPosition);
   }
   else{
    //Error
    Serial.println(invalidInput);
   }

   previousServoPosition = servoPosition;
}
