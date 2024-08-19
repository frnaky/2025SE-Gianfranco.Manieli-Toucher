#include "ultra.h"

// ultra class implementation
long ultra::measureDuration() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    return pulseIn(echoPin, HIGH);
}

int ultra::calculateDistance(long duration) {
  return duration * 0.034 / 2;
}

void ultra::begin() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void ultra::bend() {
  long duration = measureDuration();
  int distance = calculateDistance(duration);
  Serial.print("distance: ");
  Serial.println(distance);
}
