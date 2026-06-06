#include <Arduino.h>

int ledPins[] = {13, 12, 14};
bool ledStates[] = {false, false, false};
int ledCount = 3;

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  Serial.println("Serial LED Control Ready");
  Serial.println("Send 1, 2, or 3 to toggle LEDs");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command >= '1' && command <= '3') {
      int index = command - '1';

      ledStates[index] = !ledStates[index];
      digitalWrite(ledPins[index], ledStates[index] ? HIGH : LOW);

      Serial.print("LED");
      Serial.print(index + 1);
      Serial.print(" ");
      Serial.println(ledStates[index] ? "ON" : "OFF");
    } else if (command != '\n' && command != '\r') {
      Serial.println("Unknown command");
    }
  }
}