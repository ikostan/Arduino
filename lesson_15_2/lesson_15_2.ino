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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudSpeed);
  Serial.println(lessonName);
  setUpPins();
}

void loop() {
  // put your main code here, to run repeatedly:

}

//Set up pins
void setUpPins(){

    Serial.println("Setting up pins...");
    
    //RGB
    pinMode(redLedPin,OUTPUT);
    pinMode(greenLedPin,OUTPUT);
    pinMode(blueLedPin,OUTPUT);

    //Sensor
    pinMode(S2,OUTPUT);
    pinMode(S3,OUTPUT);
    pinMode(outPin,INPUT);

    Serial.println("Finished setting up pins.");
}
