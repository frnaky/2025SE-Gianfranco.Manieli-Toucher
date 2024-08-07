#include "ultra_test.h"
#include <Arduino.h>

long measureDuration() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    return pulseIn(echoPin, HIGH);
}

int calculateDistance(long duration) {
  return duration * 0.034 / 2;
}