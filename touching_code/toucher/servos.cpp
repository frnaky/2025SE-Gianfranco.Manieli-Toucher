#include "servos.h"
#include <Arduino.h>
#include <Servo.h>

MyServo::MyServo() : pos(0) {}

void MyServo::begin() {
    servo.attach(5);  
}

void MyServo::bend() {
    for (pos = 0; pos <= 180; pos += 1) {
        servo.write(pos);
        delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
        servo.write(pos);
        delay(15);
    }
}
