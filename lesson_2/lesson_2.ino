//Global variables
int OnBoardLEDpin = 13; //Create a variable and assign a pin number to it
int RedLEDpin = 12; //Create a variable and assign a pin number to it
int waitTimeOn = 500; //Waiting time in milli-sec
int waitTimeOff = 1000; //Waiting time in milli-sec

void setup() {
  // put your setup code here, to run once:
  
  pinMode(OnBoardLEDpin, OUTPUT); //Setup pin number and in/out role
  pinMode(RedLEDpin, OUTPUT); //Setup pin number and in/out role
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RedLEDpin, LOW); //Setup read/write function -> turns LED off
  digitalWrite(OnBoardLEDpin, HIGH); //Setup read/write function -> turns LED on
  
  delay(waitTimeOn); //Sleep in milli-sec
  
  digitalWrite(RedLEDpin, HIGH); //Setup read/write function -> turns LED on
  digitalWrite(OnBoardLEDpin, LOW); //Setup read/write function -> turns LED off
  
  delay(waitTimeOff); //Sleep in milli-sec
}
