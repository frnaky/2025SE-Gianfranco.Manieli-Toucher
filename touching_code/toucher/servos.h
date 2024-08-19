#include <Servo.h>

#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>

class MyServo {
private:
    int pos = 0;
    Servo servo;

public:
    MyServo();    
    void begin();
    void bend();

};



#endif

