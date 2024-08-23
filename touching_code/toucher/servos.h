#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>

class MyServo {
private:
    int pos;
    Servo servo;
public:
    MyServo();    
    virtual void begin(int pin);
    virtual void bend();
    void setPosition(int angle);
};

class Servo0 : public MyServo{ //100
public:
  void bend() override;
private:
};

class Servo1 : public MyServo{ //90
public:
  void bend() override;
private:
};

class Servo2 : public MyServo{ //20
public:
  void bend() override;
private:
};

class Servo3 : public MyServo{ //90
public:
  void bend() override;
private:
};

class Servo4 : public MyServo{ //30 open  80 close
public:     
  void bend() override;
  open();
  close();
private:
};

class controller {
private:
    Servo0 servo0;
    Servo1 servo1;
    Servo2 servo2;
    Servo3 servo3;
    Servo4 servo4;
public:
    void begin(int pin0, int pin1, int pin2, int pin3, int pin4);
    void bend();
};



#endif

