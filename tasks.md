# Tasks

## Basic

1. Install Arduino IDE and establish contakt with ESP32-C3
    * Install application
    * Add esp32 boards in Arduino IDE
    * Mount esp32 in breadboard
    * Connect esp32 to computer
    * Establish serial connection (with output)

2. Prepare esp32
    * Erase esp32 flash
    * Create and upload simple program:
      * Print "Hello world" on serial console
    * Blink med onboard LED


### Input

3. Knapp
    * Koble på knapp
    * Når knapp trykkes ned skru onboard LED på

4. Potentiometer
    * Koble på potentiometer
    * Lese potentiometer og printe verdi

5. Bevegelsessensor (PIR, AM312)
    * Koble opp sensor
    * Lese sensor og vise status med onboard LED

6. Temperatursensor (DS18B20)
    * Koble opp sensor
    * Lese sensor og vise temperatur


### Output

7. Lysdiode (LED)
    * Koble på ekstern LED
    * Blink med ekstern LED

8. LED panel (MAX7219 LED panel med 8 stk. 7-segment tall)
    * Koble på MAX7219 LED panel
    * Enkelt program som initierer og teller opp på display

9. Nanopixel (WS2812)
    * Koble på LED strip med 8x nanopixel
    * Importere Nanopixel bibliotek
    * Basic lys på nanopixel


## Viderekommende

### Tellere

10. Binær teller
    * Koble på fire LED
    * Lage teller program og sette lys på LEDs som viser tallet (binært)

11. Knapp og teller
    * Koble på knapp
    * Når knapp trykkes, øke teller

12. Led panel
    * Koble på MAX7219
    * Lage teller som viser tallene på display

13. Neopixel
    * Vis teller output ved å sette lys på pixler


### Analog input

14. Potentiometer og Neopixel
    * Benytt potentiometer som input
    * Lyse opp neopixel basert på analog input med forskjellige farger

15. Potentiometer og LED display
    * Benytt potentiometer som input
    * Vis posisjonen til potentiometer i prosent på display

16. Temperatursensor og LED display
    * Hente verdi fra DS18B20
    * Vise temperatur på MAX7219 display

