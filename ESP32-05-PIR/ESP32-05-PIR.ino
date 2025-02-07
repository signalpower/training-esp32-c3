/*
 * ESP32-05-PIR
 *
 * Checks if the Passive Infrared Receiver (PIR) for motion
 * NOTE: On ESP32-C3 SuperMini this will show some false positives.
 *       The unshielded CPU on the board is the suspected reason.
 *
 */

#define PIR_PIN 10

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  PIR motion sensor  * * * * * * * * * *\n\n");

  pinMode(PIR_PIN, INPUT_PULLUP);
  //Wait for PIR to become ready
  delay(2000);
}//setup

void loop() {
  pirState = digitalRead(PIR_PIN);
  if (pirState == HIGH) {
    Serial.print("Motion detected! ");
    //Wait before next time we can detect
    delay(2000);
  }//if
}//loop

//EOF
