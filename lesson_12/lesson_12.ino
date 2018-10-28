//Source:  https://www.youtube.com/watch?v=VIa_QZWIonQ&index=12&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-

const String lessonName = "LESSON 12: \nSimple and Easy Way to Read Strings Floats and Ints over Arduino Serial Port";
const int baudSpeed = 9600;
const String askForName = "\nWhat is your name?";
const String askForAge = "\nHow old are you?";
const String askForHeight = "\nHow toll are you (in meters)?";
const int sleepTime = 1000;

//Variables:
String personName; //Holds persons name
int personAge;  //Holds persons age
float personHeight; //Holds persons height


void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed); //Turn on serial port at 9600 baud
  Serial.println(lessonName);
}

void loop() {
  // put your main code here, to run repeatedly:

  personName = getName(false);
  
  //In order to avoid empty names we will check the length 
  while(personName.length() <= 1){
    
    personName = getName(true); //Get user input from the serial port
  }
  
  personAge = getAge();

  personHeight = getHeight(false);
  //In order to avoid 0.00 we will check the imput
  while(personHeight == 0){
    
    personHeight = getHeight(true); //Get user input from the serial port
  }
  
  sayHello(personName, personAge, personHeight);
}

//Get user name
String getName(bool isInvalidName){

  if(isInvalidName == false){
    Serial.println(askForName);
  }

  while(Serial.available() == 0){
    //Do nothing and wait for input  
  }
  
  String name = Serial.readString();
  name.trim(); //Clean the string from spaces
  
  return name;
}

//Get user age
int getAge(){

  Serial.println(askForAge);

  while(Serial.available() == 0){
    //Do nothing and wait for input  
  }
  
  return Serial.parseInt(); //Get user input from the serial port and return it
}

//Get user height
float getHeight(bool isInvalidName){

  if(isInvalidName == false){
    Serial.println(askForHeight);
  }

  while(Serial.available() == 0){
    //Do nothing and wait for input  
  }
  
  return Serial.parseFloat(); //Get user input from the serial port and return it
}

//Say hello to a new user (list all user data)
void sayHello(String personName, int personAge, float personHeight){

  Serial.println("\nHello " + personName + ". It is nice to meet you.");
  Serial.println("You are " + String(personAge) + " years old.");
  Serial.println("You are " + String(personHeight) + " meters toll.");
}
