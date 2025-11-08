#include "sdcard.h"

#define SPI_SPEED SD_SCK_MHZ(4)
#define DO_PIN 26
#define SCK_PIN 25
#define DI_PIN 27
#define CS_PIN 14


void initializeSDCard() {
  SPI.begin(SCK_PIN, DO_PIN, DI_PIN, CS_PIN);

  if (!sd.begin(CS_PIN, SPI_SPEED)) {
    if (sd.card() -> errorCode()) {
      Serial.println("SD initialization failed!");
    } else if (sd.vol() -> fatType() == 0) {
      Serial.println("Can't find a valid FAT16/FAT32 partition!");
    } else {
      Serial.println("Can't determine error type!");
    }

    return;
  }
}

void listFiles() {
  Serial.println("Files on SDCard:");
  Serial.println("  Size    Name");

  sd.ls(LS_R | LS_SIZE);
  delay(10000);
}