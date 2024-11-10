#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 10
#define NEOPIXEL_NUMPIXELS 8

Adafruit_NeoPixel pixels(NEOPIXEL_NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

int neoCounter;
uint32_t pixelColorOn;
uint32_t pixelColorOff;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  Neopixel counter  * * * * * * * * * *\n\n");
  pixels.begin();
  neoCounter = 0;
  pixelColorOn = pixels.Color(32, 8, 0);    // R, G, B
  pixelColorOff = pixels.Color(0, 0, 0);    // R, G, B
}//setup()

void loop() {
//  pixels.clear();
  for (int i=0; i<NEOPIXEL_NUMPIXELS; i++) {
    byte bitValue = bitRead(neoCounter, i);
    if (bitValue == 0) {
      pixels.setPixelColor(i, pixelColorOff);
    } else {
      pixels.setPixelColor(i, pixelColorOn);
    }//if..else
  }//for
  pixels.show();
  if (neoCounter >= 255) {
    neoCounter = 0;
  } else {
    neoCounter++;
  }//if..else
  delay(1000);
}//loop()