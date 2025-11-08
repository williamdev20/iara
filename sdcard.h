#ifndef SDCARD_H
#define SDCARD_H

#include <Arduino.h>
#include <SdFat.h>

extern SdFat sd;

void initializeSDCard();
void listFiles();

#endif