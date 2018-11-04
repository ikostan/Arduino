//Source:  https://www.youtube.com/watch?v=fE4m7TyLd8M

//Potentiometer is reading the voltage between 0 and 1023.

const String lessonName = "LESSON 16: Controlling a Servo with Arduino";
const int baudSpeed = 9600;
const int waitTime = 250; //Wait time in ms
const float convertionRate = 204.6; // 1023 devided by 5

//Pins
const int servoControlPin = 9; //Servo controlling pin
const int potentiometerAnalogPin = A0; //Potentiometer reading pin

//Logs
const String turnLeft = "<--";
const String turnRight = "-->";
const String potentiometerValue = "Potentiometer: ";
const String voltageValue = "Voltage: ";

//Variables
int currentRate;
float voltage;

//Setup
void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed); //Sets the data rate in bits per second (baud) for serial data transmission
  Serial.println(lessonName);
  pinMode(potentiometerAnalogPin, INPUT); // set analog pin A0
  pinMode(servoControlPin, OUTPUT);
}

//Main loop
void loop() {
  // put your main code here, to run repeatedly:

  currentRate = analogRead(potentiometerAnalogPin); //Reading from potentiometer
  voltage = currentRate / convertionRate; //Convert input from potentiometer in to VOLTS
  Serial.println(potentiometerValue + String(currentRate) + ". " + voltageValue + String(voltage) + ".");
  delay(waitTime);
}
