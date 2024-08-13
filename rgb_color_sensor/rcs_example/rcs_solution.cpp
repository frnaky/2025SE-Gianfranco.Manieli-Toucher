#include "rcs_solution.h"
#include <Arduino.h.

Adafruit_TCS34725::setup() {
  Serial.begin(9600);
  myservo.attach(9); //attach servo to pin 9
  if (tcs.begin()) {
    Serial.println("sensor detected");
  } else {
    Serial.println("sensot not found");
    while (1);
  }
}

Adafruit_TCS34725::loop() {
    
}