/*
 * ESP32-07-LED
 *
 * Blink an (external) LED and print the current state in serial console
 *
 */

#define LEDPIN 10

bool ledon = false;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  LED blink start  * * * * * * * * * *\n\n");
  pinMode(LEDPIN, OUTPUT); 
}//setup

void loop() {
  if (ledon) {
    Serial.println("off");
    digitalWrite(LEDPIN, LOW);
    ledon = false;
  } else {
    Serial.println("on");
    digitalWrite(LEDPIN, HIGH);
    ledon = true;
  }//if..else
  delay(1000); 
}//loop

//EOF
