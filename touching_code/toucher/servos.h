#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>


class MyServo {
protected:
    Servo servo;
    int pos;
public:
    MyServo();
    virtual void begin(int pin);
    virtual void bend();
    void setPosition(int angle);
};

class Servo0 : public MyServo {
public:
    void bend() override;
};

class Servo1 : public MyServo {
public:
    void bend() override;
};

class Servo2 : public MyServo {
public:
    void bend() override;
};

class Servo3 : public MyServo {
public:
    void bend() override;
};

class Servo4 : public MyServo {
public:
    void bend() override;
    void open();
    void close();
};

class Controller {
private:
    Servo0 servo0;
    Servo1 servo1;
    Servo2 servo2;
    Servo3 servo3;
    Servo4 servo4;
public:
    void begin(int pin0, int pin1, int pin2, int pin3, int pin4);
    void bend();
    void movement(const char* color);
};

#endif


