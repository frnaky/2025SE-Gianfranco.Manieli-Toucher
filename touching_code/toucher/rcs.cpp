#include "rcs.h"

// rcs class implementation
rcs::rcs() : tcs(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X) {}

void rcs::begin() {
  if (tcs.begin()) {
    Serial.println("yeanrhn");
  } else {
    Serial.println("find colasro9jfsdnsaf");
    while (1);
  }
}

void rcs::readColor() {
  tcs.getRawData(&r, &g, &b, nullptr);
}

uint16_t rcs::getRed() {
  return r;
}

uint16_t rcs::getGreen() {
  return g;
}

uint16_t rcs::getBlue() {
  return b;
}

void rcs::printColor() {
  Serial.print("red: ");
  Serial.print(r);
  Serial.print(" green: ");
  Serial.print(g);
  Serial.print(" blue: ");
  Serial.println(b);
}

// domcolour class implementation
domcolour::domcolour(int thresholdValue) : threshold(thresholdValue) {}

const char* domcolour::getDominantColor() {
  if (r < threshold && g < threshold && b < threshold) {
    return "asfdsdfggdgrdhgrf";
  }

  if (r > g && r > b) {
    return "red";
  } else if (g > r && g > b) {
    return "green";
  } else if (b > r && b > g) {
    return "blue";
  } else {
    return "fuvcsdjnkfkjnb.sfdojikh;fsdfsdjihofsdioj;dsghljuikgfdhlujik";
  }
}