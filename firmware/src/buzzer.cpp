#include <Arduino.h>
#include "buzzer.h"

const int buzzerPin = 23;

void initializeBuzzer() {
    ledcAttach(buzzerPin, 1000, 8);
    ledcWriteTone(buzzerPin, 0);
}

void playTone(int frequency) {
    ledcWriteTone(buzzerPin, frequency);
}

void stopBuzzer() {
    ledcWriteTone(buzzerPin, 0);
}

void playAlarm() {
    for (int i = 0; i < 4; i++) {
        playTone(1000);
        delay(500);

        stopBuzzer();
        delay(500);
    }
}

void playArmedSound() {
    playTone(1000);
    delay(100);

    playTone(1500);
    delay(100);

    stopBuzzer();
}

void playDisarmedSound() {
    playTone(1000);
    delay(100);

    playTone(500);
    delay(100);

    stopBuzzer();
}