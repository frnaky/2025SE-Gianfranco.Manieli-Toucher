#ifndef toucher_h
#define toucher_h

#include <Arduino.h>

// led
#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"

// rcs
#include <Wire.h>
#include <Adafruit_TCS34725.h>

// servo
#include <Servo.h>


class toucher {

}

class led_array {
private:
    ArduinoLEDMatrix matrix;

public:
    led_array();
    void setup();
    void loop();
};

class ultra {
private:
    long measureDuration();
    int calculateDistance(long duration);
public:
    const int trigPin = 9;
    const int echoPin = 10;
    long duration;
    int distance;
};


class rcs {
public:
    ColorSensor();
    void begin();
    void readColor();
    uint16_t getRed();
    uint16_t getGreen();
    uint16_t getBlue();
    void printColor();
protected:
    uint16_t r, g, b;
    Adafruit_TCS34725 tcs;
};

class domcolour : public rcs {
  public:
    domcolour(int threshold = 100);
    const char* getDominantColor();
  
  private:
    int threshold; //this is basically saying what miimum values i will detect
};

class servo {
private:
    int pos = 0;

public:
    MyServo();    
    void setup();
    void loop();
};

#endif