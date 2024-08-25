#include <Adafruit_TCS34725.h>
#include <Wire.h>

// icnlude other headser
#include "toucher.h"
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
  led.begin("v0.2.6");

//trig, echo pins
  ultraSensor.begin(A0, A2);

//scl and sda pins
  colorSensor.begin();

//pin numbers 0, 1, 2, 3, 4, 
  controller.begin(11, 5, 3, 7, 9);
}

void loop(void) {
  led.bend();

  //print distance
  ultraSensor.bend();

  // all for color, output domcolor
  colorSensor.readColor();
  //colorSensor.printColor();
  const char* dominantColor = colorSensor.getDominantColor();
  //use dominantColor for choosing color

  //testing if color is working
  //Serial.println(dominantColor);

  //servo!!
  delay(500);
  controller.movement(dominantColor);
  delay(100);
}


