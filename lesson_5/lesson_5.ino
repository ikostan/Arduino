String loopNumber = "Loop #: ";
String redLEDon = "Red LED is on... ";
String redLEDoff = "Red LED is off... ";
String greenLEDon = "Green LED is blinkin...";
String greenLEDonNum = "Blink #: ";
String startMessage = "Starting lesson #5: Working with Strings in Arduino";
int greenLED = 12;
int redLED = 11;
int sleepTime = 1000;
int shortSleepTime = 70;
int portNum = 9600;
int n = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(portNum);
  Serial.print(startMessage + '\n');
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println();
  Serial.print(loopNumber + n + '\n');
  
  Serial.println('\n' + greenLEDon + '\n');
  for(int i=0; i<=10; i=i+1){

    digitalWrite(greenLED, HIGH);
    Serial.print(greenLEDonNum + (i+1) + '\n');
    delay(shortSleepTime);
    digitalWrite(greenLED, LOW);
    delay(shortSleepTime);
    }

  n=n+1; 

  Serial.println('\n' + redLEDon + '\n');
  digitalWrite(redLED, HIGH);
  delay(sleepTime);
  digitalWrite(redLED, LOW);
  Serial.println(redLEDoff);
}
