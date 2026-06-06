#include <Arduino.h>

int ledPins[] = {13, 12, 14, 27, 26, 25};
int ledCount = 6;
int delayTime = 300;

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}
