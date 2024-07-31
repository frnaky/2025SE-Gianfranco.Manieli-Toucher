#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

void setup(void) {
  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("sensor detected");
  } else {
    Serial.println("sensot not found");
  }
}

void loop(void) {
  uint16_t r, g, b, c;

  tcs.getRawData(&r, &g, &b, &c);

  Serial.print("r: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("g: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("b: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("c: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
}
