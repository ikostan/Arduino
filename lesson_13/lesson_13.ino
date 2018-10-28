//Source:  https://www.youtube.com/watch?v=gqAHOoqo3OI&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-&index=13

const String lessonName = "LESSON 13: Controlling an RGB LED with Arduino";
const int baudSpeed = 9600;
const int sleepTime = 1000;

//Pins
const int pinBlue = 6;
const int pinGreen = 10;
const int pinRed = 11;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed);
  Serial.println(lessonName);
  setUpPins();
}

void loop() {
  // put your main code here, to run repeatedly:

}

//Set-up analog pins
void setUpPins(){

  pinMode(pinBlue, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinRed, OUTPUT);
}
