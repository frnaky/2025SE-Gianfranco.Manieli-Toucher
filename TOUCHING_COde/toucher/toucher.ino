#include <Adafruit_TCS34725.h>
#include <Wire.h>

//as of this comment 19/08, led and ultra and color are 100% working at all do not touch.

// icnlude other headser
#include "toucher.h"
//#include "servos.h"
#include "led_array.h"
#include "rcs.h"
#include "ultra.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

//Servo myservo;
domcolour colorSensor;
led_array led;
ultra ultraSensor;

void setup(void) {
  Serial.begin(9600);
  led.begin();
  ultraSensor.begin();
  colorSensor.begin();
  //myservo.attach(9);
}

void loop(void) {
  led.bend();
  ultraSensor.bend();

// all for color, output domcolor
  colorSensor.readColor();
  const char* dominantColor = colorSensor.getDominantColor();
//use dominantColor for choosing color
  Serial.println(dominantColor);
  delay (100);
}
