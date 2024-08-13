#ifndef MY_SERVO_H
#define MY_SERVO_H

#include <Servo.h>
#include <Arduino.h>

class MyServo {
private:
    int pos;
    Servo servo; // Add a Servo object

public:
    MyServo();    
    void setup();
    void loop();
};

#endif
