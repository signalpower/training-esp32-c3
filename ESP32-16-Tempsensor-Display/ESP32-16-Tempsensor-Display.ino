/*
 * ESP32-16-Tempsensor-Display
 *
 * Basically a thermometer using a temperature sensor to read and
 * LED display to show the temperature
 *
 */

#include <GyverSegment.h>       // For LED display (MAX7219)
#include <OneWire.h>            // Used by DallasTemperature
#include <DallasTemperature.h>  // To use temperature sensor (DS18B20)

#define DIO_PIN 10              // 7-segment MAX7219 - DIN pin (data)
#define CLK_PIN  6              // 7-segment MAX7219 - CLK pin
#define LAT_PIN  7              // 7-segment MAX7219 - CS pin
#define TEMP_PIN 4              // pin used for DS18B20

Disp7219<1> disp(DIO_PIN, CLK_PIN, LAT_PIN);    // 7-segment display, from GyverSegment library

OneWire oneWireTemp(TEMP_PIN);                  // oneWire instance to communicate with DS18B20 (may be used for any OneWire devices, not just Dallas temperature ICs)
DallasTemperature sensorTemp(&oneWireTemp);     // Pass our oneWire reference to Dallas Temperature.
DeviceAddress sensorA;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("* * * * * * * * * * 7-segment display and temperature sensor * * * * * * * * * *");
  disp.brightness(8);
  sensorTemp.begin();
  sensorTemp.getAddress(sensorA, 0);
  sensorTemp.setResolution(sensorA, 12);
}//setup

void loop() {
  unsigned long millischeck = 0;
  sensorTemp.requestTemperatures();
  float tempC = sensorTemp.getTempCByIndex(0);   // index 0 is first oneWire unit

  disp.clear();
  disp.setCursorEnd();
  disp.printRight(true);
  if (tempC != DEVICE_DISCONNECTED_C) {
    float tempCr = round(tempC * 10) / 10;
    Serial.print("Temperature: ");
    Serial.print(tempCr, 1);
    Serial.println("ºC");
    disp.print(tempCr, 1);
  } else {
    Serial.println("Error: Could not read temperature data");
    disp.print("ERROR");
  }//if..else
  disp.update();
}//loop

//EOF
