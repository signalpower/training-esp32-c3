/*
 * ESP32-05-PIR
 *
 * Checks if the Passive Infrared Receiver (PIR) for motion
 * NOTE: Make sure to shield the data pin using a ferrite bead to reduce
 *       the possibility of false positives
 */

#define PIR_PIN 10
int prevState;
uint32_t motionStart = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  PIR motion sensor  * * * * * * * * * *\n\n");

  pinMode(PIR_PIN, INPUT_PULLUP);
  //Wait for PIR to become ready
  delay(2000);
}//setup

void loop() {
  int pirState = digitalRead(PIR_PIN);
  if (pirState != prevState) {
    prevState = pirState;
    if (pirState == HIGH) {
      motionStart = millis();
      Serial.println("Motion detected!");
    } else {
      Serial.println("No more motion! Lasted: " + String(millis() - motionStart) + "ms");
    }//if
  }//if
}//loop

//EOF