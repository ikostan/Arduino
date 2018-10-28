int redPin = 11;
int greenPin = 12;
int sleepTime = 500;
int loopNum = 1;
const long baudSpeed = 115200;

int redOnTime = 250;
int redOffTime = 250;
int greenOnTime = 250;
int greenOffTime = 250;

int numRedBlinks;
int numGreenBlinks;

bool isValidInput = false;

String blnkNum;
String setupMsg = "Setup is finished";
String loopMsg = "A new loop is started. Total loops #: ";
String inputError = "ERROR: only digits allowed! Please reenter.";

String blnkMsg = "\nCurrent blinkin LED color is ";
String userInputStart ="\nPlease enter number of blinks for the ";
String userInputEnd = " LED:\n";

String redMsgOn = "Red is ON";
String redMsgOff = "Red is OFF";
String ledColorRed = "RED";

String greenMsgOn = "Green is ON";
String greenMsgOff = "Green is OFF";
String ledColorGreen = "GREEN";

String startMsg = "Lesson #6";


void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  //Serial.println(startMsg);
  //Serial.println(setupMsg);

Serial.println(userInputStart + ledColorRed + userInputEnd);

  while(isValidInput == false){   
    while (Serial.available() == 0){
      //Wait for user input 
    }
  
      numRedBlinks = Serial.parseInt();
      
      if (numRedBlinks != 0){
        isValidInput = true;
      }
      else{
        Serial.println(inputError);
      }
  }
   
  isValidInput = false;

  //Serial.flush();
  Serial.println(userInputStart + ledColorGreen + userInputEnd);
  
  while(isValidInput == false){   
    while (Serial.available() == 0){
      //Wait for user input 
    }
  
      numGreenBlinks = Serial.parseInt();
      
      if (numGreenBlinks != 0){
        isValidInput = true;
      }
      else{
        Serial.println(inputError);
      }
    }
   
  isValidInput = false; 
}

void loop() {
  // put your main code here, to run repeatedly:

  
  //Serial.println(loopMsg + loopNum);
  //delay(sleepTime);
  //loopNum = loopNum + 1;

  Serial.println(blnkMsg + ledColorRed);
  blnkNum = String(numRedBlinks);
  Serial.println("\nnumRedBlinks => " + blnkNum + "\n");
  for(int i=0; i<numRedBlinks; i=i+1){

    digitalWrite(redPin,HIGH);
    Serial.println(redMsgOn);
    delay(redOnTime);
    
    digitalWrite(redPin,LOW);
    Serial.println(redMsgOff);
    delay(redOffTime);
    }

  Serial.println(blnkMsg + ledColorGreen);
  blnkNum = String(numGreenBlinks);
  Serial.println("\nnumGreenBlinks => " + blnkNum + "\n");
  for(int j=0; j<numGreenBlinks; j=j+1){
        
    digitalWrite(greenPin,HIGH);
    Serial.println(greenMsgOn);
    delay(greenOnTime);
    
    digitalWrite(greenPin,LOW);
    Serial.println(greenMsgOff);
    delay(greenOffTime);
    }
}
