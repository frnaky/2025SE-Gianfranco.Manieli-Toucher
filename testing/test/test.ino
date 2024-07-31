#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);
ArduinoLEDMatrix matrix;


int potpin = 0;
int val;
int pos = 0;
//ultrasonic
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup(void) {
  Serial.begin(9600);
  matrix.begin(); 
  if (tcs.begin()) {
    Serial.println("sensor detected");
  } else {
    Serial.println("sensot not found");
  }
}

void loop(void) {
  uint16_t r, g, b, c;

  tcs.getRawData(&r, &g, &b, &c);

  Serial.print("r: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("g: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("b: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("c: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");

  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(25);
  const char text[] = " v0.01";
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);  
  matrix.endText(SCROLL_LEFT);
  matrix.end();
}
