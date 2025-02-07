/*
 * ESP32-11-Button_counter
 *
 * When the button is pressed the counter increases and is printed to serial
 *
 */

#define BUTTON_PIN 10

//Reverse logic with pullup resistor
#define BUTTON_PRESSED 0
#define BUTTON_OPEN    1

int buttonState = 0;
int counter = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  Button start  * * * * * * * * * *\n\n");
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}//setup

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == BUTTON_PRESSED) {
    Serial.print("Button pressed! ");
    counter++;
    Serial.println(counter);
    delay(300);
  }//if

}//loop

//EOF
