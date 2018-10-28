int greenPin = 12;
int redPin = 11;
int sleepTime = 200;
int shortSleepTime = 100;
int n = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  /*
  //Old code:
  digitalWrite(greenPin, HIGH);
  delay(sleepTime);
  
  digitalWrite(greenPin, LOW);
  delay(shortSleepTime);
  digitalWrite(redPin, HIGH);
  
  delay(sleepTime);
  digitalWrite(redPin, LOW);
  delay(shortSleepTime);
  */

  for(int j=1; j<=n; j++){
    digitalWrite(greenPin, HIGH);
    delay(sleepTime);
    digitalWrite(greenPin, LOW);
    delay(sleepTime);
    }

    for(int j=1; j<=n; j++){
    digitalWrite(redPin, HIGH);
    delay(sleepTime);
    digitalWrite(redPin, LOW);
    delay(sleepTime);
    }
}
