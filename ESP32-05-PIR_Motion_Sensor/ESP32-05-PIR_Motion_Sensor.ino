#define PIR_PIN 10

#define PIR_WAITLOOPS 15
#define PIR_LOOPTIME 500

#define PIR_CHECKLOOPS 3
#define PIR_CHECKTIME 100

#define PIR_MOTION_WAIT 4000

int prevState = LOW;
int motionCounter;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n* * * * * * * * * *  PIR Motion sensor  * * * * * * * * * *\n\n");
  pinMode(PIR_PIN, INPUT_PULLUP);
  Serial.print("Waiting for PIR to become ready");
  for (int w = 0; w <= PIR_WAITLOOPS; w++) {
    Serial.print(".");
    delay(PIR_LOOPTIME);
  }//for
  Serial.println("done!\n");
} //setup

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    if (prevState == HIGH) {
      //Ongoing motion
      motionCounter++;
      Serial.println(motionCounter);
    } else {
      //New motion
      Serial.println("Motion detected");
      motionCounter = 1;
    }//if..else
    prevState = HIGH;
  } else {
    prevState = LOW;
    motionCounter = 0;
  }//if..else
  delay(PIR_LOOPTIME);
}//loop()
