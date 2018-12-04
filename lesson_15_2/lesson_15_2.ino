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

//
#define lessonName "LESSON 15: Arduino Color Sensor and RGB LED"

// RGB LED pins:
#define redLedPin 11   //Red
#define greenLedPin 10 //Green
#define blueLedPin 6   //Blue

// Color Sensor pins:
#define S2 7 //S2
#define S3 8 //S3
#define outPin 4 //OUT

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
