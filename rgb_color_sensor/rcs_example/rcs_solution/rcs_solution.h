#ifndef RCS_SOLUTION_H
#define RCS_SOLUTION_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_TCS34725.h>

class ColorSensor {
public:
  ColorSensor();
  void init();
  void readColor();
  uint16_t getRed();
  uint16_t getGreen();
  uint16_t getBlue();
  void printColor();

private:
  Adafruit_TCS34725 tcs;
  uint16_t r, g, b;
};

#endif
