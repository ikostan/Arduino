//Source:  https://www.youtube.com/watch?v=fE4m7TyLd8M

//Potentiometer is reading the voltage between 0 and 1023.

const String lessonName = "LESSON 16: Controlling a Servo with Arduino";
const int baudSpeed = 9600;
const int waitTime = 500; //Wait time in ms

//Pins
const int servoControl = 9; //Servo controlling pin
const int potentiometerAnalogPin = A0; //Potentiometer reading pin

//Logs
const String turnLeft = "<--";
const String turnRight = "-->";
const String voltage = "Voltage: ";

//Variables
int currentRate;

//Setup
void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed); //Sets the data rate in bits per second (baud) for serial data transmission
  Serial.println(lessonName);
  pinMode(potentiometerAnalogPin, INPUT); // set analog pin A0
}

//Main loop
void loop() {
  // put your main code here, to run repeatedly:

  currentRate = analogRead(potentiometerAnalogPin);
  Serial.println(voltage + String(currentRate));
  delay(waitTime);
}
