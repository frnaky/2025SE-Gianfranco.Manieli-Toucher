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

rcs::rcs() : tcs(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X) {}

void rcs::setup() {
  if (tcs.begin()) {
    Serial.println("colour sensor detect");
  } else {
    Serial.println("cannot find colour sensor");
    while (1);
  }
}

void rcs::readColor() {
  tcs.getRawData(&r, &g, &b, nullptr);
}

uint16_t rcs::getRed() {
  return r;
}

uint16_t rcs::getGreen() {
  return g;
}

uint16_t rcs::getBlue() {
  return b;
}

void rcs::printColor() {
  Serial.print("red: ");
  Serial.print(r);
  Serial.print(" green: ");
  Serial.print(g);
  Serial.print(" blue: ");
  Serial.println(b);
}

domcolour::domcolour(int thresholdValue) : threshold(thresholdValue) {}

const char* domcolour::getDominantColor() {
  if (r < threshold && g < threshold && b < threshold) { //if value too low then rgb not exist
    return "rgb value too low";
  }

  if (r > g && r > b) {
    return "red";
  } else if (g > r && g > b) {
    return "green";
  } else if (b > r && b > g) {
    return "blue";
  } else {
    return "wronggg idiot haha";
  }

//servo

myservo::myservo() {}

void myservo::setup() {
    servo.attach(9); // Attach the servo to pin 9
}

void myservo::loop() {
    for (pos = 0; pos <= 180; pos += 1) {
        servo.write(pos); // Use the servo object to write the position
        delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
        servo.write(pos); // Use the servo object to write the position
        delay(15);
    }
}
