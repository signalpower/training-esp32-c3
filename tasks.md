# Tasks

## Basic

1. Install Arduino IDE and establish contact with ESP32-C3
  * Install application
  * Add esp32 boards in Arduino IDE
  * Mount esp32 in breadboard
  * Connect esp32 to computer
  * Establish serial connection (with output)

2. Prepare esp32
  * Erase esp32 flash
  * Create and upload simple program:
    * Print "Hello world" on serial console
    * Blink with onboard onboard LED


### Input
| ## | Title  | Steps | Breadboard image |
| -- | ------ | ----- | ---------------- |
|  3
| Button
|  * Connect button to breadboard and cable to controller
  * Blink onboard LED when button is pushed.
| <img src="/ESP32-03-Button/ESP32-03-Button.png" width=50% height=50%>
|


3. Button
  * Connect button to breadboard and cable to controller
  * Blink onboard LED when button is pushed.

 &nbsp; <img src="/ESP32-03-Button/ESP32-03-Button.png" width=50% height=50%>

4. Potentiometer
  * Connect potentiometer
  * Read potentiometer and print value

5. Movement sensor (PIR, AM312)
  * Connect sensor
  * Read sensor and show status using onboard LED

6. Temperature sensor (DS18B20)
  * Connect sensor
  * Download and use `DallasTemperature` and `OneWire` libraries
  * Read sensor and output temperature


### Output

7. Light emitting diode (LED)
  * Connect external LED
  * Blink external LED

8. LED panel (MAX7219 LED panel with 8 x 7-segment digits)
  * Connect MAX7219 LED panel
  * Download and use `GyverSegment` library
  * Create a simple program that initializes and counts up on display

9. Neopixel (WS2812)
  * Connect LED strip with 8x neopixels
  * Download and use `Adafruit Neopixel` library
  * Create a basic program that lights up the neopixels


## Beginner

### Counters

10. Binary counter
  * Connect 4 LEDs
  * Create a program that counts and light up the LEDs showing the number (binary)

11. Button and counter
  * Connect a button
  * Create a program that increses the counter when the button is pushed

12. 7-segment LED panel
  * Connect the 7-segment LED panel (MAX7219)
  * Create a program that counts and shows the number on the display

13. Neopixel
  * Connect a neopixel strip (8 pixels)
  * Create a program that counts and shows the number on the neopixels (binary)


### Analog input

14. Potentiometer and Neopixel
  * Connect potmeter and neopixels
  * Use the potmeter as input and neopixels as output
  * Create a program that lights up the neopixels based on the input
    **Hint**: The neopixels can have many colors

15. Potentiometer and LED display
  * Connect potmeter and LED display (MAX7219)
  * Use potmeter as input and LED display as output
  * Create a program that shows the position of the potmeter in percent on the display

16. Temperature sensor and LED display
  * Connect temperature sensor and 7-segment LED display
  * Use the temperature sensor as input and display as output
  * Create a program that shows the temperature on the display


