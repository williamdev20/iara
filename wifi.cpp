#include "wifi.h"

#define LED_RED 23 // WiFi connection failure
#define LED_GREEN 22 // sucessfull WiFi connection

void initializeWifi() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    Serial.println("Searching for WiFi connection...");
    delay(500);
  }

  digitalWrite(LED_RED, LOW);
  Serial.println("Sucessfully connected!");
  digitalWrite(LED_GREEN, HIGH);
}


void checkWifi() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();

    while (WiFi.status() != WL_CONNECTED) {
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED, HIGH);
      Serial.println("WiFi connection lost. Attempting to restablish...");
      delay(100);
    }

    digitalWrite(LED_RED, LOW);
    Serial.println("WiFi connection sucessfully restablished!");
    digitalWrite(LED_GREEN, HIGH);
  }
}
