#include "toucher.h"

byte gammatable[256];

// led_array class implementation
led_array::led_array() : matrix() {}

void led_array::setup() {
    Serial.begin(9600);
    matrix.begin();
}

void led_array::loop() {
    matrix.beginDraw();
    matrix.stroke(0XFFFFFFFF);
    matrix.textScrollSpeed(50);
    const char text[] = " v0.1.0";
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 0xFFFFFF);
    matrix.println(text); 
    matrix.endText(SCROLL_LEFT);
    matrix.end();
    Serial.println("led code running");
}

// ultra class implementation
void ultra::init() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void ultra::bend() {
  long duration = measureDuration();
  int distance = calculateDistance(duration);
  Serial.print("distance: ");
  Serial.print(distance);
}

long ultra::measureDuration() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    return pulseIn(echoPin, HIGH);
}

int ultra::calculateDistance(long duration) {
  return duration * 0.034 / 2;
}

// rcs class implementation
rcs::rcs() : tcs(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X) {}

void rcs::begin() {
  if (tcs.begin()) {
    Serial.println("yeanrhn");
  } else {
    Serial.println("colo sensor not found");
    while (1);
  }
}

void rcs::readColor() {
  tcs.getRawData(&r, &g, &b, nullptr);
}

uint16_t rcs::getRed() {
  return r;
}

uint16_t rcs::getGreen() {
  return g;
}

uint16_t rcs::getBlue() {
  return b;
}

void rcs::printColor() {
  Serial.print("red: ");
  Serial.print(r);
  Serial.print(" green: ");
  Serial.print(g);
  Serial.print(" blue: ");
  Serial.println(b);
}
 
// domcolour class implementation
domcolour::domcolour(int thresholdValue) : threshold(thresholdValue) {}

const char* domcolour::getDominantColor() {
  if (r < threshold && g < threshold && b < threshold) {
    return "not meeting threshold";
  }

  if (r > g && r > b) {
    return "red";
  } else if (g > r && g > b) {
    return "green";
  } else if (b > r && b > g) {
    return "blue";
  } else {
    return "no color findd";
  }
}
//servoo !
MyServo::MyServo() {}

void MyServo::init() {
    servo.attach(9);
}

void MyServo::bend() {
    for (pos = 0; pos <= 180; pos += 1) {
        servo.write(pos);
        delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
        servo.write(pos);
        delay(15);
    }
}
