#include <Arduino.h>
#include "pir.h"

const int pirPin = 22;
int previousState = LOW;

void initializePIR() {
    pinMode(pirPin, INPUT);
    previousState = digitalRead(pirPin);
}

bool motionDetected() {
    int currentState = digitalRead(pirPin);

    bool detected = (previousState == LOW && currentState == HIGH);

    previousState = currentState;

    return detected;
}