// Include required libraries

#include "Arduino.h"

#include "SPI.h"
#include "Audio.h"
#include "SD.h"
#include "FS.h"

#include <WiFi.h>
#include "time.h"


int motion = 13  ;
int sensor = 23 ;
int cnt  = 11;

int time_welcome = 6000 ;
int time_goodbye = 4000 ;

char *sound_vao  = "/vao.mp3";
char *sound_ra = "/ra.mp3";

int vol =  10 ;
int mo ;
//File dataFile;

#define SD_CS    15//12//16
#define SPI_MOSI  22//15//17
#define SPI_MISO  21//4//18
#define SPI_SCK   4//14//5
 
// I2S Connections
#define I2S_DOUT       32//26
#define I2S_BCLK       25//27
#define I2S_LRC        26//14
 
 // Create Audio object
Audio audio ;

unsigned long startTime ;
 
void setup() {
   // setup  sensor , motion and Serial 
  pinMode(motion , INPUT);

  pinMode(sensor, INPUT_PULLUP);
  Serial.begin(115200);
  
    // // Set microSD Card CS as OUTPUT and set HIGH
    pinMode(SD_CS, OUTPUT);
    digitalWrite(SD_CS, HIGH);
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    SPI.setFrequency(1000000);
      if (!SD.begin(SD_CS, SPI))
      {
        Serial.println("Card Mount Failed");
        while (1);
    }
    else
    {
    }
    
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(vol); // 0...21
    startTime = millis() ;

//
  //dataFile.connecttoFS(SD, "datalog.txt");
  /*dataFile = SD.open("datalog.txt");
  if (!dataFile) {
    Serial.println("Không thể mở tệp datalog.txt");
    return;
  }*/

  //
/*   
  // Kết nối WiFi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected."); */
  
/*   // Lấy thông tin thời gian
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  //Ngắt kết nối WiFi khi không cần dùng đến
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF); */
  mo = 0;
}

void loop()
{  
  //int time_max = 10000 ;
  // đo liên tiếp 200 lần mỗi lần cách nhau 0.01 giây 
  if (digitalRead(motion) == 1)mo += 1 ; else mo -= 1;
  if (mo < -100 ) mo = -100 ;
  if (mo > 100 ) mo = 100 ;
  delay(10);
  if ( digitalRead(sensor) == 1){
     if (mo > -20 ){ 
      Serial.println("Goodbye") ;
      play(sound_ra , time_goodbye) ;
    }
    else {
      Serial.println("Hello") ;
      play(sound_vao , time_welcome) ; 
    }
  }
  while (digitalRead(sensor) == 1 )delay(10);

  Serial.print(mo);
  Serial.print("    motion : ") ;
  Serial.print(digitalRead(motion));
  Serial.print("    sensor : ");
  Serial.println(digitalRead(sensor));
  //delay(1000) ;



}

/* void printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  dataFile.println(&timeinfo, " %H:%M:%S");
}  */


void play( char *sound, int time){
  startTime = millis() ;
  unsigned long currentTime = millis();  // Lấy thời điểm hiện tại
  unsigned long elapsedTime = currentTime - startTime;  // Tính thời gian đã trôi qua
  audio.connecttoFS(SD, sound);
  while ( elapsedTime  < time){ 
    audio.loop(); 
    currentTime = millis();  // Lấy thời điểm hiện tại
    elapsedTime = currentTime - startTime;  // Tính thời gian đã trôi qua
  }

}

void sound_welcome(){
  Serial.println("Hello World!");
  audio.connecttoFS(SD,sound_vao);
  startTime = millis() ;
  unsigned long currentTime = millis();  // Lấy thời điểm hiện tại
  unsigned long elapsedTime = currentTime - startTime;  // Tính thời gian đã trôi qua
  while ( elapsedTime  < time_welcome){ 
  audio.loop(); 
  currentTime = millis();  // Lấy thời điểm hiện tại
  elapsedTime = currentTime - startTime;  // Tính thời gian đã trôi qua
  }
}

void sound_goodbye(){
  Serial.println("GoodBye!");
  audio.connecttoFS(SD,sound_ra);
  startTime = millis() ;
  unsigned long currentTime = millis();  // Lấy thời điểm hiện tại
  unsigned long elapsedTime = currentTime - startTime;  // Tính thời gian đã trôi qua
  while ( elapsedTime  < time_goodbye ){ 
  
  audio.loop();
  currentTime = millis();  // Lấy thời điểm hiện tại
  elapsedTime = currentTime - startTime;  // Tính thời gian đã trôi qua
  }
}