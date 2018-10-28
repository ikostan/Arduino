// Ohm law: V=I*R (V - voltage in volts, R - resistance in Ohms, I - current in Amps)
// Voltage equation calculation for analog pin: V * 204.6, where 0 is 0V and 1023 is 5V.
// Source: https://www.youtube.com/watch?v=QsYcYknKbB0&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-&index=10

const float baudSpeed = 115200;
const int analogPinZero = A0; //Pin A0, analog pin for reading voltage
const int sleepTime = 250;
const float voltToAnalog = 204.6; // 5 devide by 1023

const String tutorialName = "Lesson #10: Reading Analog Voltages with Arduino.";

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(baudSpeed);
  Serial.println(tutorialName);
  pinMode(analogPinZero, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int readVoltageValue = analogRead(analogPinZero);
  float volts = float(readVoltageValue) / voltToAnalog;
  Serial.println("Current value is " + String(readVoltageValue) + ", and it's equal to " + String(volts) + " volts");
  delay(sleepTime);
}
