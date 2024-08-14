#include "rcs_solution.h"

ColorSensor tcs;

void setup() {
  Serial.begin(9600);
  tcs.init();
}

void loop() {
  tcs.readColor();
  tcs.printColor();
  delay(1000);
}