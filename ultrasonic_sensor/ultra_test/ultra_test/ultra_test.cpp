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

ultra::setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

ultra::loop() {
  long duration = measureDuration();
  int distance = calculateDistance(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
}