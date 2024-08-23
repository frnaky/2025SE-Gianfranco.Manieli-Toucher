#include <Adafruit_TCS34725.h>
#include <Wire.h>

//as of this comment 19/08, led and ultra and color are 100% working at all do not touch.

//as of 20/08 i am touching led ultra and color haha

//21/08

/* to do in class
make sure led matrix works, and changing led.bedn() changes led matrix
make sure ultrasonic outputs proper distance, and chaning pins in ultraSensor.bend() works
work on color sensor dominant code, have a look at  gammatable
servo
*/


// icnlude other headser
//#include "toucher.h"
#include "servos.h"
#include "led_array.h"
#include "rcs.h"
#include "ultra.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

Controller controller;
domcolour colorSensor;
led_array led;
ultra ultraSensor;
MyServo myservo;

void setup(void) {
  Serial.begin(9600);
//version number
  led.begin("v0.2.5");
//trig, echo pins
  ultraSensor.begin(A0, A2);
  colorSensor.begin();
//pin numbers 0, 1, 2, 3, 4, 
  controller.begin(11, 5, 3, 7, 9);
}

void loop(void) {
  //version number
  led.bend();
  ultraSensor.bend();

  // all for color, output domcolor
  colorSensor.readColor();
  //colorSensor.printColor();
  const char* dominantColor = colorSensor.getDominantColor();
  //use dominantColor for choosing color
  //Serial.println(dominantColor);

  //servo!!
  //bend is default pos
  controller.bend();

  delay(100);
  controller.movement(dominantColor);
  delay(100);
}


