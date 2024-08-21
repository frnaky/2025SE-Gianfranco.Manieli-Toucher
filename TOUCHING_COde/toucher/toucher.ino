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
#include "toucher.h"
//#include "servos.h"
#include "led_array.h"
#include "rcs.h"
#include "ultra.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS394725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

//MyServo myservo;
domcolour domcol;
led_array led;
ultra ultraSensor;
tcs rgb;

void setup(void) {
  Serial.begin(9600);
  led.begin();
  ultraSensor.begin(A0, A3);
  rgb.begin();
  domcol.begin();
  //myservo.begin();
  //servo0.begin();
  //servo1.begin();
 // servo2.begin();
  //servo3.begin();
  //servo4.begin();
}

void loop(void) {
  led.bend("v0.1.7");
  ultraSensor.bend();
  //myservo.bend();
// all for color, output domcolor
  rgb.printColor();
  //domcol.readColor();
  //const char* dominantColor = domcol.getDominantColor();
//use dominantColor for choosing color
  //Serial.println(dominantColor);
  //delay (100);
}
