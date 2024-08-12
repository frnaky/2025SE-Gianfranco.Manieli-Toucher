#ifndef ultra_test_h
#define ultra_test_h


class ultra {
private:
public:
    const int trigPin = 9;
    const int echoPin = 10;
    long measureDuration();
    int calculateDistance(long duration);
};

#endif