#include "myServo.h"

MyServo::MyServo() : pos(0) {}

void MyServo::setup() {
    Serial.begin(9600);
    servo.attach(9); // Attach the servo to pin 9
}

void MyServo::loop() {
    for (pos = 0; pos <= 180; pos += 1) {
        servo.write(pos); // Use the servo object to write the position
        delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
        servo.write(pos); // Use the servo object to write the position
        delay(15);
    }
}
