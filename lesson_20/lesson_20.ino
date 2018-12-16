#include <LiquidCrystal.h> //Include LCD library

// LESSON 20: Ultrasonic Sensor and LCD on Arduino for Distance Measurements
// Source: http://www.toptechboy.com/arduino/lesson-20-arduino-lcd-project-for-measuring-distance-with-ultrasonic-sensor/
// Youtube: https://www.youtube.com/watch?v=AzS_0aXDlW4&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-&index=21

/*
Connections for Sparkfun Inventor Kit LCD
(for others column 1 might be different)
LCD Pin #  LCD PIN NAME  Arduino Pin

1     VSS                 GND
2     VDD                 5V
3     V0                  Pot Center Pin
4     RS                  10
5     RW                  GND
6     E                   9
7     DB0                 NOT CONNECTED
8     DB1                 NOT CONNECTED
9     DB2                 NOT CONNECTED
10    DB3                 NOT CONNECTED
11    DB4                 Pin 5
12    DB5                 Pin 4
13    DB6                 Pin 3
14    DB7                 Pin 2
15    Backlight LED +V    5V
16    Backlight LED GND   GND
*/

#define tutorialName1 "LESSON 20"
#define tutorialName2 "UsSING LCD"
#define tutorialName3 "WITH US SENSOR"

int myCounter;// Declare a counter
#define sleepTime 1500

LiquidCrystal LCD(10,9,5,4,3,2); //Create LCD object

void setup() {
  // put your setup code here, to run once:
  LCD.begin(16,2); // LCD size 16 columns, 2 rows
  LCD.setCursor(0,0); //Set LCD cursor to upper left corner
  printTitle();
}

void loop() {
  // put your main code here, to run repeatedly:


}


//Print lesson title
void printTitle(){

  LCD.setCursor(0,0); //Set cursor to 1 column (0) and 1 row (0)
  LCD.print(tutorialName1); //print title
  delay(sleepTime); //sleep
  LCD.clear(); //clear LCD
  LCD.print(tutorialName2); //print
  LCD.setCursor(0,1); //Set cursor to 1 column (0) and 2nd row (1)
  LCD.print(tutorialName3); //print
  delay((sleepTime * 2));
  LCD.clear();
}
