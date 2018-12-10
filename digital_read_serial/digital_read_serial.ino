//Source: https://www.arduino.cc/en/Tutorial/DigitalReadSerial

#define button 2
#define led 13
#define baudSpeed 9600
#define tutorialName "Digital Read Serial" 
#define sleepTime 250
int buttonState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudSpeed);
  Serial.println(tutorialName);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);
  if(buttonState > 0){
    Serial.println("On");
    digitalWrite(led, HIGH);
    }
  else{
    Serial.println("Off");
    digitalWrite(led, LOW);
    }
  delay(sleepTime);
}
