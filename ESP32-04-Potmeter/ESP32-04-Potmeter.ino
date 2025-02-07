/*
 * ESP32-04-Potmeter/ESP32-04-Potmeter.ino
 *
 * Reads the position of the potmeter and prints:
 *  - Analog value
 *  - Byte (0-255) value based on analog
 *  - Voltage (0-3.3 V) based on analog
 *
 */

#define POT_PIN 3

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  Potmeter start  * * * * * * * * * *\n\n");
  analogSetAttenuation(ADC_11db);
}//setup

void loop() {
  int analogValue = analogRead(POT_PIN);
  float voltage = floatMap(analogValue, 0, 4095, 0, 3.3);
  unsigned char byteVal = convertAD(analogValue, 4095);

  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Byte: ");
  Serial.print(byteVal);
  Serial.print(", Voltage: ");
  Serial.println(voltage);
  delay(1000);
}//loop


float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}//floatMap

unsigned char convertAD(int analogVal, int analogMax) {
  float factor = analogMax / 255;
  unsigned char returnValue = analogVal/factor;
  return returnValue;
}//convertAD

//EOF
