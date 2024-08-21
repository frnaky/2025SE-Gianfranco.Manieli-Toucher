#include <Servo.h>

#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>

class MyServo {
private:
    int pos = 0;
    Servo servo;
public:
    MyServo();    
    void begin();
    void bend();
};

class servo0 : public MyServo{ //100
    public:
    private:
};

class servo1 : public MyServo{ //90
    public:
    private:
};

class servo2 : public MyServo{ //20
    public:
    private:
};

class servo3 : public MyServo{ //90
    public:
    private:
};

class servo4 : public MyServo{ //30 open  80 close
    public:
    private:
};



#endif

