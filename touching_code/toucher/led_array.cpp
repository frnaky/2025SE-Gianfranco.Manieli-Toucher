#include "led_array.h"

led_array::led_array() : matrix() {}

void led_array::begin(const char* vernum) {
    Serial.begin(9600);
    matrix.begin();
    vernumber = vernum;
}

void led_array::bend() {
    matrix.beginDraw();
    matrix.stroke(0XFFFFFFFF);
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 0xFFFFFF);
    matrix.println(vernumber); 
    matrix.endText(SCROLL_LEFT);
    matrix.end();
}
