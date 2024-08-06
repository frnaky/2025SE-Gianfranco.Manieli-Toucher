#include "ultra_test.h"

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  long duration = measureDuration();
  int distance = calculateDistance(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
}