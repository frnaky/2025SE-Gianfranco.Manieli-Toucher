#include "servos.h"
#include <Arduino.h>
#include <Servo.h>

MyServo::MyServo() : pos(0) {}

void MyServo::begin(int pin) {
    servo0.attach(pin0); 
    servo1.attach(pin1);
    servo2.attach(pin2);
    servo3.attach(pin3);
    servo4.attach(pin4); 
}

void MyServo::bend() {
}

void MyServo::setPosition(int angle) {
    pos = angle;
    servo.write(pos);
}

void Servo0::bend() {
    setPosition(100);
}

void Servo1::bend() {
    setPosition(90);
}

void Servo2::bend() {
    setPosition(20);
}

void Servo3::bend() {
    setPosition(90);
}

void Servo4::bend() {
    setPosition(90);
}

void Servo4::open() {
    setPosition(30);
}

void Servo4::close() {
    setPosition(80);
}

void controller::begin(int pin0, int pin1, int pin2, int pin3, int pin4) {
    servo0.begin(pin0);
    servo1.begin(pin1);
    servo2.begin(pin2);
    servo3.begin(pin3);
    servo4.begin(pin4);
}

void controller::bend() {
    servo0.bend();
    servo1.bend();
    servo2.bend();
    servo3.bend();
    servo4.bend();
}