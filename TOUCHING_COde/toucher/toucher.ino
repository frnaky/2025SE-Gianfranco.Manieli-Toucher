#include <Adafruit_TCS34725.h>
#include <Wire.h>
#include <Servo.h>
#include "toucher.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

Servo myservo;
domcolour colorSensor;

void setup(void) {
  Serial.begin(9600);
  led_array led;
  ultra ultraSensor;

  led.setup();
  ultraSensor.setup();
  colorSensor.begin();
  myservo.attach(9);
}

void loop(void) {
// all for color, output domcolor
  colorSensor.readColor();
  const char* dominantColor = colorSensor.getDominantColor();
//use dominantColor for choosing color
  Serial.println(dominantColor);
  delay (1000);
}
