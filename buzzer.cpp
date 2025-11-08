#include "buzzer.h"

#define BUZZER_PIN 21

void playBuzzer() {
  pinMode(BUZZER_PIN, OUTPUT);

  tone(BUZZER_PIN, 880, 120);
  delay(150);
  tone(BUZZER_PIN, 988, 120);
  delay(150);
  tone(BUZZER_PIN, 1319, 350);
  delay(400);

  noTone(BUZZER_PIN);
}