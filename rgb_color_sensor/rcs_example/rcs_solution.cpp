#include "rcs_solution.h"
#include <Arduino.h.

rcs::rcs() : tcs(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X) {}

void ColorSensor::init() {
  if (tcs.begin()) {
    Serial.println("colour sensor detect");
  } else {
    Serial.println("cannot find colour sensor");
    while (1);
  }
}

void ColorSensor::readColor() {
  tcs.getRawData(&r, &g, &b, nullptr);
}

uint16_t ColorSensor::getRed() {
  return r;
}

uint16_t ColorSensor::getGreen() {
  return g;
}

uint16_t ColorSensor::getBlue() {
  return b;
}

void ColorSensor::printColor() {
  Serial.print("Red: ");
  Serial.print(r);
  Serial.print(" Green: ");
  Serial.print(g);
  Serial.print(" Blue: ");
  Serial.println(b);
}