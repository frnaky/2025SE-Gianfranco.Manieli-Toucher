#include "servos.h"
#include <Arduino.h>
#include <Servo.h>

MyServo::MyServo() : pos(0) {}

void MyServo::begin(int pin) {
    servo.attach(pin);
}

void MyServo::bend() {
}

void MyServo::setPosition(int angle) {
    pos = constrain(angle, 0, 180);
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
    Servo0.begin(pin0);
    Servo1.begin(pin1);
    Servo2.begin(pin2);
    Servo3.begin(pin3);
    Servo4.begin(pin4);
}

void controller::bend() {
    Servo0.bend();
    Servo1.bend();
    Servo2.bend();
    Servo3.bend();
    Servo4.bend();
}