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
    void begin(int pin);
    void bend();
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
private:
};



#endif

