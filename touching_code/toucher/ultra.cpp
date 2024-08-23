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

void Controller::movement(const char* color) {
    if (strcmp(color, "Red") == 0) {
        servo4.setPosition(/* Red position */);
    } else if (strcmp(color, "Green") == 0) {
        servo4.setPosition(/* Green position */);
    } else if (strcmp(color, "Blue") == 0) {
        servo4.setPosition(/* Blue position */);
    } else if (strcmp(color, "Yellow") == 0) {
        servo4.setPosition(/* Yellow position */);
    } else {
        // Default position if color is not recognized
        servo4.setPosition(90);
    }
}