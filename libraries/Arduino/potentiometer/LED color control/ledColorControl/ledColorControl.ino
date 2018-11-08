#include <Adafruit_NeoPixel.h>

#define PIN 9

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  
}

void loop() {
  
  
    
  
int sensorValue = map(analogRead(A0), 0, 1024, 0, 255);
int sensorValue2 = map(analogRead(A1), 0, 1024, 0, 255);
int sensorValue3 = map(analogRead(A2), 0, 1024, 0, 255);

 
  strip.setPixelColor(0, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(1, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(2, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(3, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(4, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(5, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(6, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(7, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(8, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(9, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(10, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(11, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(12, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(13, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(14, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(15, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(16, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(17, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(18, sensorValue, sensorValue2, sensorValue3);
  strip.setPixelColor(19, sensorValue, sensorValue2, sensorValue3);
  
 
strip.show();
 }
