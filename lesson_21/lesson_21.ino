//#include <LiquidCrystal.h>    //Include LCD library
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

//SD card variables:
#define sd_cs (4)

//Generic variables
#define tutorialName1 "LESSON 21"
#define tutorialName2 "LOG SENSOR DATA"
#define tutorialName3 "TO AN SD CARD"
#define sleepTime 1500
#define baudSpeed 9600
String fileName = "PTData.txt";

//LiquidCrystal LCD(10,9,5,4,3,2); //Create LCD object


float tempC;  // Variable for holding temp in C
float tempF;  // Variable for holding temp in F
float pressure; //Variable for holding pressure reading

File mySensorData; //Data object you will write your sesnor data to

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

void setup() {
  // put your setup code here, to run once:

  //Serial monitor
  Serial.begin(baudSpeed); //Start Serial Monitor
  Serial.println("LESSON 21: LOG SENSOR DATA TO AN SD CARD");

  Serial.print("\nInitializing SD card...");

  if(testSdCard()){
    SD.begin(sd_cs); //Initialize the SD card reader
    //getCardType();
    //getVolumeData();
  }
}

void loop() {

  mySensorData = SD.open(fileName, FILE_WRITE);

  if(!mySensorData){
    Serial.println("ERROR: SD card failure!");
  }
  else{
    Serial.println("Writing data...");
    mySensorData.println("test");  
    mySensorData.close();  
  }
    
  delay(sleepTime);
}


bool testSdCard(){

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_HALF_SPEED, sd_cs)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    Serial.println("\nPlease verify all the above and restart your device.");
    while (1);
    return false;
  } else {
    Serial.println("Wiring is correct and a card is present.");
    return true;
  }
}

/*
// print the type of card
void getCardType(){
  
  Serial.println();
  Serial.print("Card type: ");
  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }
  
  Serial.println();
}


// print the type and size of the first FAT-type volume
void getVolumeData(){

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    while (1);
  }
  
  Serial.print("Volume type is:    FAT");
  Serial.println(volume.fatType(), DEC);

  uint32_t volumesize;

  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize /= 2;                           // SD card blocks are always 512 bytes (2 blocks are 1KB)
  Serial.print("Volume size (Kb):  ");
  Serial.println(volumesize);
  Serial.print("Volume size (Mb):  ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Gb):  ");
  Serial.println((float)volumesize / 1024.0); 
}
*/
