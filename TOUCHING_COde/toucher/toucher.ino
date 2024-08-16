#include <Adafruit_TCS34725.h>
#include <Wire.h>
#include <Servo.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

Servo myservo;
domcolour colorSensor;

void setup(void) {
  Serial.begin(9600);
  led_array.setup()
  ultra.setup()
  rcs.setup()
  myservo.setup()
}

void loop(void) {



// all for color, output domcolor
  colorSensor.readColor();
  const char* dominantColor = colorSensor.getDominantColor();
  Serial.println(dominantColor);
  delay (1000);
  
}
