#include "api.h"
#include "wifi.h"
#include "sdcard.h"
#include "secrets.h"
#include "buzzer.h"

SdFat sd;


void getSound(String phrase) {
  String encodedPhrase = urlEncode(phrase);

  HTTPClient http;
  String language = "pt-br";

  String url = String("http://api.voicerss.org/?key=") +
    API_KEY +
    "&hl=" + language +
    "&src=" + encodedPhrase;

  http.begin(url);

  int httpStatus = http.GET();

  if (httpStatus == 200) {

    if (!sd.exists("/sounds")) {
      sd.mkdir("/sounds");
    }

    String filePath = "/sounds/voice.mp3";
    File file = sd.open(filePath, FILE_WRITE);

    WiFiClient *stream = http.getStreamPtr();
    uint8_t buffer[512];
    int bytesRead;

    Serial.println("Dowloading sound...");

    while (http.connected() && (bytesRead = stream -> readBytes(buffer, sizeof(buffer))) > 0) {
      file.write(buffer, bytesRead);
    }

    file.close();
    http.end();
    Serial.println("Sound dowloaded sucessfully!");
    playBuzzer();

  } else {
    Serial.println("Error accessing the API! Status: ");
    Serial.println(httpStatus);
  }
}