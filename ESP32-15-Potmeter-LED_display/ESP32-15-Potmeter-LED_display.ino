#include <GyverSegment.h>

#define POT_PIN 0

#define DIO_PIN 10
#define CLK_PIN  6
#define LAT_PIN  7

Disp7219<1> disp(DIO_PIN, CLK_PIN, LAT_PIN);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  Potmeter & 7-segment display * * * * * * * * * *\n\n");
  disp.brightness(8);
}//setup()

void loop() {
  int analogValue = analogRead(POT_PIN);
  float pctValue = (double)analogValue / 4095 * 100;

  disp.clear();
  disp.setCursorEnd();
  disp.printRight(true);
  disp.print(pctValue,1);
  disp.update();

  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Percent: ");
  Serial.print(pctValue);
  Serial.println();
  delay(300);
}//loop()

//EOF