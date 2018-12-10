//Source: https://www.arduino.cc/en/Tutorial/StateChangeDetection

#define button 2
#define led 13
#define baudSpeed 9600
#define tutorialName "State Change Detection" 
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
  
  delay(sleepTime);
}
