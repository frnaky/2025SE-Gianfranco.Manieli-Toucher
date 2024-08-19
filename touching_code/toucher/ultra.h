#ifndef ULTRA_H
#define ULTRA_H
#include <Arduino.h>
class ultra {
private:
    long measureDuration();
    int calculateDistance(long duration);
public:
    const int trigPin = A0;
    const int echoPin = A2;
    void begin();
    void bend();
};

#endif