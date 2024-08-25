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
    setPosition(30);
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
    servo4.grab();
}

void Controller::grab() {
    servo0.setPosition(100);
    servo1.setPosition(135);
    servo2.setPosition(135);
    servo3.setPosition(135);
    servo4.setPosition(20); //open
    delay(500);
    servo4.setPosition(80); //close
    delay(100);
}

void Controller::redPlace() {
    servo0.setPosition(150);
    delay(50);
    servo1.setPosition(90);
    delay(50);
    servo2.setPosition(20);
    delay(50);
    servo3.setPosition(90);
    delay(50);
    servo4.open();
    delay(50);
}

void Controller::greenPlace() {
    servo0.setPosition(150);
    delay(50);
    servo1.setPosition(90);
    delay(50);
    servo2.setPosition(20);
    delay(50);
    servo3.setPosition(90);
    delay(50);
    servo4.open();
    delay(50);
}

void Controller::bluePlace() {
    servo0.setPosition(150);
    delay(50);
    servo1.setPosition(90);
    delay(50);
    servo2.setPosition(20);
    delay(50);
    servo3.setPosition(90);
    delay(50);
    servo4.open();
    delay(50);
}

void Controller::movement(const char* color) {
    this->bend();

    if (strcmp(color, "red") == 0) {

        this->redPlace();
        delay(100);
        this->grab();
    } else if (strcmp(color, "green") == 0) {
        this->greenPlace();
        delay(100);
        this->grab();
    } else if (strcmp(color, "blue") == 0) {
        this->bluePlace();
        delay(100);
        this->grab();
    } else {
        // default pos
        this->bend();
    }
}

