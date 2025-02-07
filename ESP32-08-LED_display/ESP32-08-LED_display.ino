/*
 * ESP32-08-LED_display
 *
 * Uses a library, GyverSegment, to show values on a LED display
 *
 */

#include <GyverSegment.h>                       // For LED display (MAX7219)

#define DIO_PIN 10                              // 7-segment MAX7219 - DIN pin (data)
#define CLK_PIN  6                              // 7-segment MAX7219 - CLK pin
#define LAT_PIN  7                              // 7-segment MAX7219 - CS pin

Disp7219<1> disp(DIO_PIN, CLK_PIN, LAT_PIN);    // 7-segment display, from GyverSegment library

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("* * * * * * * * * * 7-segment display * * * * * * * * * *");
  disp.brightness(8);
}//setup

void loop() {
  // Clear display buffer
  disp.clear();
  // Reset cursor (left)
  disp.home();
  // Print text
  disp.print("HELLO");
  // Update display to show content
  disp.update();
  delay(3000);

  // Clear display buffer
  disp.clear();
  // Reset cursor (left)
  disp.home();
  // Print integer
  disp.print(23456789);
  // Update display to show content
  disp.update();
  delay(3000);

  // Clear display buffer
  disp.clear();
  // Set cursor at end (right hand side)
  disp.setCursorEnd();
  // Print from the right
  disp.printRight(false);
  // Print float (decimal) number
  disp.print(123.45);
  // Update display to show content
  disp.update();
  delay(1000);

}//loop

//EOF
