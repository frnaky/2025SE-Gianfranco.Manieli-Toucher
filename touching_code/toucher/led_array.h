#ifndef LED_ARRAY_H
#define LED_ARRAY_H

#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"

class led_array {
private:
  ArduinoLEDMatrix matrix;

public:
  led_array();
  void begin();
  void bend();
};

#endif 