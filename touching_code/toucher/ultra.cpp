#include "ultra.h"

// ultra class implementation

ultra::ultra() : trigPin(-1), echoPin(-1) {}

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

void ultra::begin(int trig, int echo) {
  trigPin = trig;
  echoPin = echo;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void ultra::bend() {
  long duration = measureDuration();
  int distance = calculateDistance(duration);
  //Serial.print("distance: ");
  Serial.println(distance);
}
