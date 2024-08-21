#ifndef ULTRA_H
#define ULTRA_H
#include <Arduino.h>

class ultra {
private:
    long measureDuration();
    int calculateDistance(long duration);
public:
    ultra();
    int trigPin;
    int echoPin;
    int distance;
    void begin(int trigPin, int echoPin);
    void bend();
};

#endif