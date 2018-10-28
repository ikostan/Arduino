int portNum = 9600;
int greenPinNum = 12;
int redPinNum = 11;
int sleepTime = 1000;
int shortSleepTime = 50;
char myStr[] = "Hello World!";
int n = 1;

void setup() {
  // put your setup code here, to run once:
  //Open a serial port for communication
  Serial.begin(portNum);
  pinMode(greenPinNum, OUTPUT);
  pinMode(redPinNum, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println();
  Serial.print("Loop #: ");
  Serial.print(n);
  Serial.println();
  
  for(int i=0; i<=11; i=i+1){
    digitalWrite(greenPinNum, HIGH);
    Serial.print(myStr[i]);
    delay(shortSleepTime);
    digitalWrite(greenPinNum, LOW); 
    delay(shortSleepTime);   
    }
  
  for(int j=0; j<=2; j=j+1){
    Serial.println();
    } 

  digitalWrite(redPinNum, HIGH);
  delay(sleepTime);
  digitalWrite(redPinNum, LOW);

  n=n+1;
}
