#include "servos.h"
#include <Arduino.h>
#include <Servo.h>

MyServo::MyServo() : pos(0) {}

void MyServo::begin(int pin0, int pin1, int pin2, int pin3, int pin4) {
    servo0.attach(pin0); 
    servo1.attach(pin1);
    servo2.attach(pin2);
    servo3.attach(pin3);
    servo4.attach(pin4); 
}

void MyServo::bend() {
}

void servo0::begin(int pin0) {
 myServo::begin(pin0);
}

void servo1::begin(int pin1) {
  myServo::begin(pin1);
}

void servo2::begin(int pin2) {
 myServo::begin(pin2);
}

void servo3::begin(int pin3) {
 myServo::begin(pin3);
}

void servo4::begin(int pin4) {
 myServo::begin(pin4); 
}



//loops
void servo0::bend() {
  setPosition(90);
}

void servo1::bend() {
  setPosition(90);
}

void servo2::bend(int pin2) {
  setPosition(90);
}

void servo3::bend(int pin3) {
  setPosition(90);
}

//claw
void servo4::bend(int pin4) {
  setPosition(90);
}