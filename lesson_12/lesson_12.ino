//Source:  https://www.youtube.com/watch?v=VIa_QZWIonQ&index=12&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-

const String lessonName = "LESSON 12: \nSimple and Easy Way to Read Strings Floats and Ints over Arduino Serial Port";
const int baudSpeed = 9600;
const String askForName = "\nWhat is your name?\n";
const String askForAge = "How old are you?";
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

  personName = getName();
  personAge = getAge();
  sayHello(personName, personAge, personHeight);
}

//Get user name
String getName(){

  Serial.println(askForName);

  while(Serial.available() == 0){
    //Do nothing and wait for input  
  }
  
  String name = Serial.readString();
  name.trim();
  
  return name;
}

//Get user age
int getAge(){

  Serial.println(askForAge);

  while(Serial.available() == 0){
    //Do nothing and wait for input  
  }
  
  return Serial.parseInt();
}

//Say hello to a new user
void sayHello(String personName, int personAge, float personHeight){

  Serial.println("\nHello " + personName + ". It is nice to meet you.");
  Serial.println("You are " + String(personAge) + " years old.");
}
