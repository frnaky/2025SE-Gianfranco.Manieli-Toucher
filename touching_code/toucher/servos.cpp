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

void Controller::begin(int pin0, int pin1, int pin2, int pin3, int pin4) {
    servo0.MyServo::begin(pin0);
    servo1.MyServo::begin(pin1);
    servo2.MyServo::begin(pin2);
    servo3.MyServo::begin(pin3);
    servo4.MyServo::begin(pin4);
}

void Controller::bend() {
    servo0.bend();
    servo1.bend();
    servo2.bend();
    servo3.bend();
    servo4.open();
}

void Controller::movement(const char* color) {
    if (strcmp(color, "Red") == 0) {
        servo4.setPosition(30);  // Example position for Red
    } else if (strcmp(color, "Green") == 0) {
        servo4.setPosition(60);  // Example position for Green
    } else if (strcmp(color, "Blue") == 0) {
        servo4.setPosition(90);  // Example position for Blue
    } else if (strcmp(color, "Yellow") == 0) {
        servo4.setPosition(120);  // Example position for Yellow
    } else {
        // Default position if color is not recognized
        servo4.setPosition(90);
    }
}

