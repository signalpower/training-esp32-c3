/*
 * ESP32-09-Neopixel
 *
 * Lights up NeoPixels, one by one
 *
 */

#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 10
#define NEOPIXEL_NUMPIXELS 8

Adafruit_NeoPixel pixels(NEOPIXEL_NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  Neopixel start  * * * * * * * * * *\n\n");
  pixels.begin();
}//setup

void loop() {
  pixels.clear();
  for (int i=0; i<NEOPIXEL_NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(32, 8, 0));
    pixels.show();
    delay(500);
  }//for
  delay(1000);
}//loop

//EOF
