#ifndef MY_SERVO_H
#define MY_SERVO_H

#include <Servo.h>
#include <Arduino.h>

class MyServo {
private:
    int pos;
    
public:
    MyServo();    
    void setup();
    void loop();
};

#endif
