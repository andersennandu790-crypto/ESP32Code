#include <Arduino.h>

int motorPins[] = {13, 12, 14, 27};
int stepDelay = 5;

int stepSequence[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void setStep(int stepIndex) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(motorPins[i], stepSequence[stepIndex][i]);
  }
}

void rotateSteps(int steps, bool clockwise) {
  for (int i = 0; i < steps; i++) {
    int stepIndex = clockwise ? i % 8 : 7 - (i % 8);
    setStep(stepIndex);
    delay(stepDelay);
  }
}

void stopMotor() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(motorPins[i], LOW);
  }
}

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(motorPins[i], OUTPUT);
    digitalWrite(motorPins[i], LOW);
  }
}

void loop() {
  rotateSteps(2048, true);
  stopMotor();
  delay(1000);

  rotateSteps(2048, false);
  stopMotor();
  delay(1000);
}