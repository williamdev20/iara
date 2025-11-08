#ifndef API_H
#define API_H

#include <Arduino.h>
#include <HTTPClient.h>
#include <UrlEncode.h>

void getSound(String phrase);
String urlEncode(String str);

#endif