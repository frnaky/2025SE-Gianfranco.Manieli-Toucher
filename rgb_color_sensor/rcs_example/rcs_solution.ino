#include "rcs_solution.h"

void setup() {
  Serial.begin(9600);
  rcs.begin();
}

void loop() {
  rcs.readColor();
  rcs.printColor();
  delay(1000);
}