#define BUTTON_PIN 10

//Reverse logic with pullup resistor
#define BUTTON_PRESSED 0
#define BUTTON_OPEN    1

int buttonState = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  Button  * * * * * * * * * *\n\n");
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}//setup()

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == BUTTON_PRESSED) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(300);
  }//if
}//loop()

//EOF