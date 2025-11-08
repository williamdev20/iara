/*

  I.A.R.A (Inteligência Assistiva de Reconhecimento Auditivo e gestual)

  More in: https://github.com/williamdev20/iara

  Copyright (C) 2025, William Alves
  Created in Brazil

*/

#include "wifi.h"
#include "sdcard.h"
#include "api.h"

void setup() {
  Serial.begin(115200);
  initializeWifi();
  initializeSDCard();
}

void loop() {
  checkWifi();
  getSound("Olá, mundo!");
  delay(10000);
  listFiles();
}
