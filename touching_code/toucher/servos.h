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

class servo0 : public MyServo{ 11 100
    public:
    private:
};

class servo1 : public MyServo{ 9 90
    public:
    private:
};

class servo2 : public MyServo{ 7 20
    public:
    private:
};

class servo3 : public MyServo{ 5 90
    public:
    private:
};

class servo4 : public MyServo{ 3 30 open  80 close
    public:
    private:
};



#endif

