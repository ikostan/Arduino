//Source: https://www.youtube.com/watch?v=d8_xXNcGYgo&index=1&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-
//LESSON 1: Simple Introduction to the Arduino


//Global variables
int LEDpin = 13; //Create a variable and assign a pin number to it
int waitTimeOn = 100; //Waiting time in milli-sec
int waitTimeOff = 900; //Waiting time in milli-sec

void setup() {
  // put your setup code here, to run once:
  
  pinMode(LEDpin, OUTPUT); //Setup pin number and in/out role
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(LEDpin, HIGH); //Setup read/write function -> turns LED on
  delay(waitTimeOn); //Sleep in milli-sec
  digitalWrite(LEDpin, LOW); //Setup read/write function -> turns LED off
  delay(waitTimeOff); //Sleep in milli-sec
}
