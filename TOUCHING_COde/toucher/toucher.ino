#include <Adafruit_TCS34725.h>
#include <Wire.h>
#include <Servo.h>
#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"
#include "toucher.h"

//Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

//domcolour colorSensor;
led_array display;
ultra ultraSensor;
MyServo myServo;

void setup() {
  Serial.begin(9600);
  display.setup();
  delay (100);
  ultraSensor.init();
  //colorSensor.begin();
  myServo.init();
}

void loop() {
  display.loop();
  ultraSensor.bend();
  myServo.bend();
// all for color, output domcolor
  //colorSensor.readColor();
  //colorSensor.printColor();
  //const char* dominantColor = colorSensor.getDominantColor();
//use dominantColor for choosing color
  //Serial.println(dominantColor);
  delay (300);
}
