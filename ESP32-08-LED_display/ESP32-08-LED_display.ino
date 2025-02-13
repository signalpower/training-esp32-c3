/*
 * ESP32-08-LED_display
 *
 * Uses a library, GyverSegment, to show values on a LED display
 *
 */

#include <GyverSegment.h> // For LED display (MAX7219)

#define DIO_PIN 10        // 7-segment MAX7219 - DIN pin (data)
#define CLK_PIN  6        // 7-segment MAX7219 - CLK pin
#define LAT_PIN  7        // 7-segment MAX7219 - CS pin

Disp7219<1> disp(DIO_PIN, CLK_PIN, LAT_PIN);    // 7-segment display, from GyverSegment library

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("* * * * * * * * * * 7-segment display * * * * * * * * * *");
  disp.brightness(8);
}//setup

void loop() {
  disp.clear();           // Clear display buffer
  disp.home();            // Reset cursor (left)
  disp.print("HELLO");    // Print text
  disp.update();          // Update display to show content
  delay(3000);
  disp.clear();           // Clear display buffer
  disp.home();            // Reset cursor (left)
  disp.print(23456789);   // Print integer
  disp.update();          // Update display to show content 
  delay(3000);
  disp.clear();           // Clear display buffer
  disp.setCursorEnd();    // Set cursor at end (right hand side)
  disp.printRight(false); // Print from the right
  disp.print(123.45);     // Print float (decimal) number 
  disp.update();          // Update display to show content 
  delay(1000);
}//loop

//EOF
