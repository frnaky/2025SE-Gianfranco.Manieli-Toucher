#include <Adafruit_TCS34725.h>
#ifndef RCS_H
#define RCS_H

class rcs {
public:
    rcs();
    void begin();
    void readColor();
    uint16_t getRed();
    uint16_t getGreen();
    uint16_t getBlue();
    void printColor();
protected:
    uint16_t r, g, b;
    Adafruit_TCS34725 tcs;
};

//dominant color!!!! 
class domcolour : public rcs {
  public:
    domcolour(int threshold = 100);
    const char* getDominantColor();
  
  private:
    int threshold; //this is basically saying what miimum values i will detect
};

#endif