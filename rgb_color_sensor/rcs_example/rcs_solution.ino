#include <Servo.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "rcs.solution.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

Servo myservo;

int potpin = 0; //change this for the potemiometer pin
int val; // variable to read the value from the analog pin
int pos = 0;
//ultrasonic
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup(void) {
  tcs.setup()
}

void loop(void) {
  uint16_t r, g, b, c;

  tcs.getRawData(&r, &g, &b, &c);

  // Serial.print("r: "); Serial.print(r, DEC); Serial.print(" ");
  // Serial.print("g: "); Serial.print(g, DEC); Serial.print(" ");
  // Serial.print("b: "); Serial.print(b, DEC); Serial.print(" ");
  // Serial.print("c: "); Serial.print(c, DEC); Serial.print(" ");
  // Serial.println(" ");

  // write with potentionamerlter 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}