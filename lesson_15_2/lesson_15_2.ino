// Source: https://www.youtube.com/watch?v=Ltp3skGLqFM&index=16&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-
// More Info: http://www.toptechboy.com/arduino/lesson-15-super-cool-arduino-color-sensor-project/
// Name: LESSON 15: Arduino Color Sensor and RGB LED

/*
How to detect color:
----------------------------
S2   |   S3   |   Color Read
----------------------------
LOW  |   LOW  |   Red
LOW  |   HIGH |   Blue
HIGH |   HIGH |   Green
----------------------------
*/

#define lessonName "LESSON 15: Arduino Color Sensor and RGB LED" //Holds lesson name
#define baudSpeed 9600 //Baud speed
#define delayTime 300  //Wait time

// RGB LED pins:
#define redLedPin 11   //Red
#define greenLedPin 10 //Green
#define blueLedPin 6   //Blue

// Color Sensor pins:
#define S2 7          //S2
#define S3 8          //S3
#define outPin 4      //OUT

/*
Measurement of the color strength.
This measurement will return a value between 0 an 102,400. 
Because of this, you need to be sure to declare pulseWidth variable an unsigned int.
*/
unsigned int pulseWidth;

//Color strength (RGB):
int rColorStrength;
int gColorStrength;
int bColorStrength;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudSpeed);
  Serial.println(lessonName);
  setUpPins();
}

void loop() {
  
  //Read red component of the color (S2 and S3 set to LOW):
  //Serial.println("Reading RED component..."); //Log
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  pulseWidth = pulseIn(outPin, LOW); //Make a mesurment  
  /*
  First we need to convert 0 to 102,400 to this range.  
  102,400/400 = 256. 
  Almost exactly what we want! But we need to subtract one. 
  So, we could say that rColorStrength = (pulseWidth/400) – 1.
  That gets us a number between 0 and 255. 
  Only problem is, remember that in the original pulseWidth, 
  big numbers mean weak colors and small numbers mean strong colors, 
  so we need to fix that. We could fix it by now saying:
  rColorStrength = (255 – rColorStrength); 
  */
  rColorStrength = (pulseWidth / 400.) - 1;
  rColorStrength = 255 - rColorStrength;

  //Read green component of the color (S2 and S3 set to HIGH):
  //Serial.println("Reading GREEN component..."); //Log
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  pulseWidth = pulseIn(outPin, LOW); //Make a mesurment
  gColorStrength = (pulseWidth / 400.) - 1;
  gColorStrength = 255 - gColorStrength;

  //Read blue component of the color (S2 LOW and S3 HIGH):
  //Serial.println("Reading BLUE component..."); //Log
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  pulseWidth = pulseIn(outPin, LOW); //Make a mesurment
  bColorStrength = (pulseWidth / 400.) - 1;
  bColorStrength = 255 - bColorStrength;

  setMaxColor();
  setMinColor();
  setMidColor();

  Serial.println("R: " + String(rColorStrength) + " | G: " + String(gColorStrength) + " | B: " + String(bColorStrength)); //Log

  //simpleRGB();

  delay(delayTime);
}

//Set up pins
void setUpPins(){

    //Serial.println("Setting up pins..."); //Log
    
    //RGB
    pinMode(redLedPin,OUTPUT);
    pinMode(greenLedPin,OUTPUT);
    pinMode(blueLedPin,OUTPUT);

    //Sensor
    pinMode(S2,OUTPUT);
    pinMode(S3,OUTPUT);
    pinMode(outPin,INPUT);

    //Serial.println("Finished setting up pins."); //Log
}

//Change RGB led color
void simpleRGB(){

  //Setting up RGB LED color:
  if(rColorStrength > gColorStrength && rColorStrength > bColorStrength){

    digitalWrite(redLedPin,HIGH);
    digitalWrite(greenLedPin,LOW);
    digitalWrite(blueLedPin,LOW);
  }

  if(gColorStrength > rColorStrength && gColorStrength > bColorStrength){

    digitalWrite(redLedPin,LOW);
    digitalWrite(greenLedPin,HIGH);
    digitalWrite(blueLedPin,LOW);
    //Serial.println("RGB led is green now"); //Log
  }

  if(bColorStrength > gColorStrength && bColorStrength > rColorStrength){

    digitalWrite(redLedPin,LOW);
    digitalWrite(greenLedPin,LOW);
    digitalWrite(blueLedPin,HIGH);
  }
}

void setMaxColor(){
  
  //Setting up RGB LED color:
  if(rColorStrength > gColorStrength && rColorStrength > bColorStrength){

    rColorStrength = 255;
  }

  if(gColorStrength > rColorStrength && gColorStrength > bColorStrength){

    gColorStrength = 255;
  }

  if(bColorStrength > gColorStrength && bColorStrength > rColorStrength){

    bColorStrength = 255;
  }
}

void setMinColor(){
  
  //Setting up RGB LED color:
  if(rColorStrength < gColorStrength && rColorStrength < bColorStrength){

    rColorStrength = 0;
  }

  if(gColorStrength < rColorStrength && gColorStrength < bColorStrength){

    gColorStrength = 0;
  }

  if(bColorStrength < gColorStrength && bColorStrength < rColorStrength){

    bColorStrength = 0;
  }
}

void setMidColor(){
  
  //Setting up RGB LED color:
  if(rColorStrength != 0 && rColorStrength != 255){

    rColorStrength = 127;
  }

  if(gColorStrength != 0 && gColorStrength != 255){

    gColorStrength = 127;
  }

  if(bColorStrength != 0 && bColorStrength != 255){

    bColorStrength = 127;
  }
}
