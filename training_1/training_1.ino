int redPin = 11;
int greenPin = 12;
int sleepTime = 500;
String redMsgOn = "Red is ON";
String redMsgOff = "Red is OFF";
//int serialPort = 115200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<3; i=i+1){
    digitalWrite(redPin, HIGH);
    Serial.println(redMsgOn);
    delay(sleepTime);
    digitalWrite(redPin, LOW);
    Serial.println(redMsgOff);
    delay(sleepTime);
  }

  for(int j=0; j<3; j=j+1){
    digitalWrite(greenPin, HIGH);
    Serial.println("Green is ON");
    delay(sleepTime);
    digitalWrite(greenPin, LOW);
    Serial.println("Green is OFF");
    delay(sleepTime);
  }
}
