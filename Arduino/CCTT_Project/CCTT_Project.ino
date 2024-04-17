// Include required libraries
#include "Arduino.h"
#include "SPI.h"
#include "SD.h"
 
//ESP32 PCB lỗ
// microSD Card Reader connections
#define SD_CS    12
#define SD_MOSI  15
#define SD_MISO  4
#define SD_SCK   14
 
// I2S Connections
#define I2S_DOUT       32
#define I2S_BCLK       25
#define I2S_LRC        26
 
//HC-SR501 Connection
#define SR501_PIN 13

//MC31 Connection
#define MC31_PIN 23

void setup() {
   
    // // Set microSD Card CS as OUTPUT and set HIGH
    pinMode(SD_CS, OUTPUT);      
    digitalWrite(SD_CS, HIGH);
   
    // Initialize SPI bus for microSD Card
    SPI.begin(SD_SCK, SD_MISO, SD_MOSI);
   
    // Start Serial Port
    Serial.begin(115200);
   
    // Start microSD Card
    if(!SD.begin(SD_CS))
    {
      Serial.println("Error accessing microSD card!");
      while(true);
    }


    
}
 
void loop()
{
    
}
