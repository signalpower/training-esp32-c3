#include <Adafruit_NeoPixel.h>

#define POT_PIN 0

#define NEOPIXEL_PIN 10
#define NEOPIXEL_NUMPIXELS 8

Adafruit_NeoPixel pixels(NEOPIXEL_NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

uint32_t pixColors[] = {
  pixels.Color(0,128,0),    // 0
  pixels.Color(0,128,0),    // 1
  pixels.Color(32,128,0),   // 2
  pixels.Color(64,128,0),   // 3
  pixels.Color(128,128,0),  // 4
  pixels.Color(128,64,0),   // 5
  pixels.Color(128,32,0),   // 6
  pixels.Color(128,0,0)     // 7
};

const float factor = 4095 / (NEOPIXEL_NUMPIXELS);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  Potmeter & Neopixel * * * * * * * * * *\n\n");
  pixels.begin();
}//setup()

void loop() {
  int analogValue = analogRead(POT_PIN);
  unsigned char numPixelCol = (analogValue / factor) + 0.5;
  
  pixels.clear();
  if (numPixelCol > 0) {
    for (int i = 1; i <= numPixelCol; i++) {
      pixels.setPixelColor(i-1, pixColors[i-1]);
    }//for
  }//if
  pixels.show();

  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", PixelCol: ");
  Serial.println(numPixelCol);
  delay(300);
}//loop()

//EOF