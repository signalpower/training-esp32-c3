#define LEDPIN 10

bool ledon = false;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  LED blink start  * * * * * * * * * *\n\n");
  pinMode(LEDPIN, OUTPUT); 
}

void loop() {
  if (ledon) {
    Serial.println("off");
    digitalWrite(LEDPIN, LOW);
    ledon = false;
  } else {
    Serial.println("on");
    digitalWrite(LEDPIN, HIGH);
    ledon = true;
  }
  delay(1000); 
}