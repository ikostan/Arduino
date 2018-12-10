//Source: https://www.arduino.cc/en/Tutorial/StateChangeDetection

#define button 2
#define led 13
#define baudSpeed 9600
#define tutorialName "State Change Detection" 
#define sleepTime 400
int ledSignal = LOW;

int buttonState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudSpeed);
  Serial.println(tutorialName);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(led, ledSignal);
  Serial.println("LED is off");
}

void loop() {

  buttonState = digitalRead(button);

  if(buttonState > 0){

    Serial.println("Button state has changed");
    
    if(ledSignal == LOW){
      ledSignal = HIGH;
      Serial.println("LED is on");
      }
    else{
      ledSignal = LOW;
      Serial.println("LED is off");
      }
    }

  digitalWrite(led, ledSignal);
  delay(sleepTime);
}
