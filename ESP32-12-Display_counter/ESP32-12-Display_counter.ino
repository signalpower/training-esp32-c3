#include <GyverSegment.h>                       // For LED display (MAX7219)

#define DIO_PIN 10                              // 7-segment MAX7219 - DIN pin (data)
#define CLK_PIN  6                              // 7-segment MAX7219 - CLK pin
#define LAT_PIN  7                              // 7-segment MAX7219 - CS pin

Disp7219<1> disp(DIO_PIN, CLK_PIN, LAT_PIN);    // 7-segment display, from GyverSegment library

int dispCounter;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("* * * * * * * * * * 7-segment display counter * * * * * * * * * *");
  disp.brightness(8);
  dispCounter = 0;
}//setup

void loop() {
  // Clear display buffer
  disp.clear();
  // Set cursor at end (right hand side)
  disp.setCursorEnd();
  // Print from the right
  disp.printRight(false);
  // Print float (decimal) number
  disp.print(dispCounter);
  // Update display to show content
  disp.update();

  if (dispCounter >= 99999999) {
    dispCounter = 0;
  } else {
    dispCounter++;
  }//if..else
  delay(10);

}//loop

//EOF