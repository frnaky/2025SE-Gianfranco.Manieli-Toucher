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
public:
    const int trigPin = 9;
    const int echoPin = 10;
    long measureDuration();
    int calculateDistance(long duration);
};


class rcs {
private:
    Adafruit_TCS34725 tcs;
    uint16_t r, g, b;

public:
    ColorSensor();
    void begin();
    void readColor();
    uint16_t getRed();
    uint16_t getGreen();
    uint16_t getBlue();
    void printColor();
    boolean begin(uint8_t addr = TCS34725_ADDRESS, TwoWire *theWire = &Wire);
};

class servo {
private:
    int pos;

public:
    MyServo();    
    void setup();
    void loop();
};

#endif