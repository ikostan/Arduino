
// Ohm law: V=I*R (V - voltage in volts, R - resistance in Ohms, I - current in Amps)
// Voltage equation calculation for analog pin: V * 204.6, where 0 is 0V and 1023 is 5V.
// Source: https://www.youtube.com/watch?v=QsYcYknKbB0&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-&index=10

const float baudSpeed = 9600;
const int analogPin = A0; //Pin A0, analog pin for reading voltage
const int ledPin = 11; //Pin 13, digital/analog pin for writing voltage
const int sleepTime = 100;
//const float voltToAnalog = 204.6; // 1023 devide by 5
//const float voltToDigital = 51; // 255 devide by 5

const String tutorialName = "Lesson #11: Using Arduino to Create Dimmable LED.";

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(baudSpeed);
  Serial.println(tutorialName);
  pinMode(analogPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int readValue = analogRead(analogPin); 
  int writeValue = (255./1023.) * readValue;
  Serial.println("LED value: " + String(writeValue));
  analogWrite(ledPin, writeValue);
  delay(sleepTime);
}
