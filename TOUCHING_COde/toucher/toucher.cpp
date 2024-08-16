#include <Arduino.h>

// led
#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"

// rcs
#include <Wire.h>
#include <Adafruit_TCS34725.h>

// servo
#include <Servo.h>


// toucher

// led
led_array::led_array() : matrix() {}

void led_array::setup() {
    Serial.begin(9600);
    matrix.begin();
}

void led_array::loop() {
    matrix.beginDraw();
    matrix.stroke(0XFFFFFFFF);
    matrix.textScrollSpeed(50);
    const char text[] = " v0.1.0";
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 0xFFFFFF);
    matrix.println(text); 
    matrix.endText(SCROLL_LEFT);
    matrix.end();
}

// ultra
long measureDuration() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    return pulseIn(echoPin, HIGH);
}

int calculateDistance(long duration) {
  return duration * 0.034 / 2;
}

ultra::setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

ultra::loop() {
  long duration = measureDuration();
  int distance = calculateDistance(duration);
  Serial.print("Distance: ");
  Serial.println(distance);
}

// rcs
void ColorSensor::init() {
  if (tcs.begin()) {
    Serial.println("colour sensor detect");
  } else {
    Serial.println("cannot find colour sensor");
    while (1);
  }
}

void ColorSensor::readColor() {
  tcs.getRawData(&r, &g, &b, nullptr);
}

uint16_t ColorSensor::getRed() {
  return r;
}

uint16_t ColorSensor::getGreen() {
  return g;
}

uint16_t ColorSensor::getBlue() {
  return b;
}

void ColorSensor::printColor() {
  Serial.print("Red: ");
  Serial.print(r);
  Serial.print(" Green: ");
  Serial.print(g);
  Serial.print(" Blue: ");
  Serial.println(b);
}

//servo
void MyServo::setup() {
    Serial.begin(9600);
    servo.attach(9); // Attach the servo to pin 9
}

void MyServo::loop() {
    for (pos = 0; pos <= 180; pos += 1) {
        servo.write(pos); // Use the servo object to write the position
        delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
        servo.write(pos); // Use the servo object to write the position
        delay(15);
    }
}
