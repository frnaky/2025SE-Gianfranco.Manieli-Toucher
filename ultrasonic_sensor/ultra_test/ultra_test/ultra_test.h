#ifndef ultra_test_h
#define ultra_test_h

const int trigPin = 9;
const int echoPin = 10;
long measureDuration();
int calculateDistance(long duration);

#endif