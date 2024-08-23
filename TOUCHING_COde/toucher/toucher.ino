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
#include "servos.h"
#include "led_array.h"
#include "rcs.h"
#include "ultra.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

domcolour colorSensor;
led_array led;
ultra ultraSensor;
MyServo myservo;

Servo0 servo0;
Servo1 servo1;
Servo2 servo2;
Servo3 servo3;
Servo4 servo4;


void setup(void) {
  Serial.begin(9600);
//version number
  led.begin("v0.2.0");
//trig, echo pins
  ultraSensor.begin(A0, A2);
  colorSensor.begin();
//pin numbers
  servo0.begin(11);
  servo1.begin(9);
  servo2.begin(7);
  servo3.begin(5);
  servo4.begin(3);
}

void loop(void) {
//version number
  led.bend();
  ultraSensor.bend();
  myservo.bend();
// all for color, output domcolor
  colorSensor.readColor();
  const char* dominantColor = colorSensor.getDominantColor();
//use dominantColor for choosing color
  Serial.println(dominantColor);
//servo!!
  servo0.bend();
  delay(1000);
  
  servo1.bend();
  delay(1000);
  
  servo2.bend();
  delay(1000);
  
  servo3.bend();
  delay(1000);
  
  servo4.bend();
}
