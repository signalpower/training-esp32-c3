int led_pins[] = {5, 6, 7, 9};

void setup() {

  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  Bin counter start  * * * * * * * * * *\n\n");

  for (int led_pin: led_pins) {
    pinMode(led_pin, OUTPUT); // initialize pins as outputs

  }//for
} //setup

void loop() {
  for (int i = 0; i <= 15; i++) {                     // Count 0 to 15 (4 bits)
    int a = 0;                                        // Bit position
    for (int led_pin: led_pins) {                     // Iterate pins
      byte bitValue = bitRead(i, a);                  // Read bit value for position
      Serial.print(bitValue);                         // Output bit value
      digitalWrite(led_pin, bitValue);                // LED on or off based on the bit value
      a++;                                            // Increment bit position
    } //for
    Serial.print(" : ");                              // Output colon as separator
    Serial.println(i);                                // Output int value with new line
    delay(1000);                                      // Wait before next integer
  } //for
}//loop()
