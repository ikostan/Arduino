#include <LiquidCrystal.h>    //Include LCD library
#include <SD.h>               //Load SD card library
#include<SPI.h>               //Load SPI Library


// LESSON 21: Data Logging from Arduino to SD card
// Source: http://www.toptechboy.com/arduino/arduino-lesson-21-log-sensor-data-to-an-sd-card/
// Youtube: https://www.youtube.com/watch?v=-nXSUXJz4QQ&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-&index=22

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


/*
The SD card reader should be connected as follows:
Connecting the SD Card Reader

Sd Card Reader Pin    Arduino Pin   Details
GND                   GND Common    Ground
3.3 V – (NOT USED)    
+5                    5V            Power
CS                    A0            Chip Select
MOSI                  11            SPI Data
SCK                   13            Clock
MISO                  12            SPI Data
GND                   GND           Common Ground
*/

//Generic variables
#define tutorialName1 "LESSON 21"
#define tutorialName2 "LOG SENSOR DATA"
#define tutorialName3 "TO AN SD CARD"
#define sleepTime 1500
#define baudSpeed 9600


LiquidCrystal LCD(10,9,5,4,3,2); //Create LCD object


float tempC;  // Variable for holding temp in C
float tempF;  // Variable for holding temp in F
float pressure; //Variable for holding pressure reading


void setup() {
  // put your setup code here, to run once:

  //Serial monitor
  Serial.begin(baudSpeed); //Start Serial Monitor
  Serial.println("LESSON 21: LOG SENSOR DATA TO AN SD CARD");

}

void loop() {
  // put your main code here, to run repeatedly:

  
  delay(sleepTime);
}
