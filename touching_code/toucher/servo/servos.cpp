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


void servo0::begin(int servoPin) {
 myServo::begin(servoPin);
}

void servo1::begin(int servoPin) {
  myServo::begin(servoPin);
}

void servo2::begin(int servoPin) {
 myServo::begin(servoPin);
}

void servo3::begin(int servoPin) {
 myServo::begin(servoPin);
}

//claw
void servo4::begin(int servoPin) {
 myServo::begin(servoPin); 
}

