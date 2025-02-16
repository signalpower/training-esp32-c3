/*
 * ESP32-06-Temp_sensor
 *
 * Uses OneWire bus to read the (Dallas) temperature sensor and prints
 * the Celsius value.
 *
 */

#include <OneWire.h>
#include <DallasTemperature.h>

#define TEMPSENSOR_ONEWIRE 10

OneWire tempBus(TEMPSENSOR_ONEWIRE);
DallasTemperature tempSensors(&tempBus);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  Temperature sensor  * * * * * * * * * *\n\n");
  tempSensors.begin();
  tempSensors.setResolution(12); //Increase resolution of read values
}//setup

void loop() {
  tempSensors.requestTemperatures();
  Serial.print("Celsius temperature: ");
  Serial.println(tempSensors.getTempCByIndex(0)); //Get temperature from the first sensor on the bus
  delay(1000); //Loop wait
}//loop

//EOF
