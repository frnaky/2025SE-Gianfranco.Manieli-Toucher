#ifndef ULTRA_H
#define ULTRA_H
#include <Arduino.h>
class ultra {
private:
    long measureDuration();
    int calculateDistance(long duration);
public:
    int trigPin
    int echoPin
    void begin();
    void bend(int trigPin, int echoPin);
};

#endif