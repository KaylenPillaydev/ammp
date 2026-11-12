#include <Arduino.h>
#include "pir.h"
#include "buzzer.h"

void setup() {
    Serial.begin(115200);
    initializePIR();
    initializeBuzzer();
}

void loop() {
    if (motionDetected()) {
        Serial.println("Motion: DETECTED");
    playAlarm();
    }
}