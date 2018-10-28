const float baudSpeed = 115200;
int sleepTime = 250;
String loopMsg = "You are in loop #: ";
int n = 20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudSpeed);
}

void loop() {                                                                                                                                                                                                                                                   
  int j = 1; // Declare an int

  while(j <= n){

    if(j%2 == 0){
      Serial.println(loopMsg + String(j));
    }
    
    j = j + 1;    
    delay(sleepTime);
  }

  Serial.println(" ");
}
