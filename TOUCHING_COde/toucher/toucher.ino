#include <Adafruit_TCS34725.h>
#include <Wire.h>

//as of this comment 19/08, led and ultra and color are 100% working at all do not touch.

//as of 20/08 i am touching led ultra and color haha

/* to do in class
make sure led matrix works, and changing led.bend() changes led matrix
make sure ultrasonic outputs proper distance, and chaning pins in ultraSensor.bend() works
work on color sensor dominant code, have a look at gammatable
servo
*/


// icnlude other headser
#include "toucher.h"
#include "servos.h"
#include "led_array.h"
#include "rcs.h"
#include "ultra.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

MyServo myservo;
domcolour colorSensor;
led_array led;
ultra ultraSensor;

void setup(void) {
  Serial.begin(9600);
  led.begin();
  ultraSensor.begin();
  colorSensor.begin();
  myservo.begin();
}

void loop(void) {
  led.bend("v0.1.5");
  ultraSensor.bend(A0, A2);
  myservo.bend();
// all for color, output domcolor
  colorSensor.readColor();
  const char* dominantColor = colorSensor.getDominantColor();
//use dominantColor for choosing color
  Serial.println(dominantColor);
  delay (100);
}
