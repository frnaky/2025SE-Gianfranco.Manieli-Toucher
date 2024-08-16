#include "rcs_solution.h"
#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <iostream>22

ColorSensor::ColorSensor() : tcs(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X) {}

void ColorSensor::init() {
  if (tcs.begin()) {
    Serial.println("Color sensor detected");
  } else {
    Serial.println("Cannot find color sensor");
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

std::string getDominantColor(int r, int g, int b) {
    if (r > g && r > b) {
        return "Red";
    } else if (g > r && g > b) {
        return "Green";
    } else if (b > r && b > g) {
        return "Blue";
    } else {
        return "No dominant color";
    }
}
