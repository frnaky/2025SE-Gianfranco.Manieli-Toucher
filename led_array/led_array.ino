#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
    Serial.begin(9600);
    matrix.begin(); 
}

void loop() {
    matrix.beginDraw();
    matrix.stroke(0xFFFFFFFF);
    matrix.textScrollSpeed(25);

    const char text[] = " v0.01";
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 0xFFFFFF);
    matrix.println(text);
    matrix.endText(SCROLL_LEFT);
    matrix.end();
}