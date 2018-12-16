#include <LiquidCrystal.h> //Include LCD library

// LESSON 19: Using LCD Display with Arduino
// Source: http://www.toptechboy.com/arduino/lesson-19-arduino-lcd-display/
// Youtube: http://www.toptechboy.com/arduino/lesson-19-arduino-lcd-display/

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

#define tutorialName1 "LESSON 19"
#define tutorialName2 "Using LCD"
#define tutorialName3 "with Arduino"

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

  LCD.setCursor(0,0); //Set cursor to 1 column (0) and 1th row (0)
  LCD.clear(); //clear LCD
  LCD.print("My Timer: ");
  
  for(myCounter = 1; myCounter <= 10; myCounter = myCounter + 1){

     LCD.setCursor(0,1); //Set cursor to 1 column (0) and 2nd row (1)
     LCD.print(String(myCounter) + " seconds"); //print
     delay(1000); //wait 1 sec
  }

  LCD.setCursor(0,0); //Set cursor to 1 column (0) and 1th row (0)
  LCD.clear(); //clear LCD
  LCD.print("My Timer: ");

  for(myCounter = 9; myCounter > 0; myCounter = myCounter - 1){

     LCD.setCursor(0,1); //Set cursor to 1 column (0) and 2nd row (1)
     LCD.print(String(myCounter) + " seconds"); //print
     delay(1000); //wait 1 sec
  }
}

//Print lesson title
void printTitle(){
  
  LCD.print(tutorialName1); //print title
  delay(sleepTime); //sleep
  LCD.clear(); //clear LCD
  LCD.print(tutorialName2); //print
  delay(sleepTime);
  LCD.clear();
  LCD.print(tutorialName3); //print
  delay(sleepTime);
  LCD.clear();
}
