#include <CheapStepper.h>

CheapStepper stepperr1 (4,5,6,7);
CheapStepper stepperr3 (16,17,18,19);
const int normalstep = 10;
const int normaldir = 11;

void setup() {
  stepperr1.setRpm(13);
  stepperr3.setRpm(13);
  pinMode(normalstep, OUTPUT);
  pinMode(normaldir, OUTPUT);

}

void loop() {

  stepperr1.moveDegreesCCW (1700);
  stepperr3.moveDegreesCCW (250);
  
  delay (1000);

  for(int z=0;z<100;z++)
  {
    stepperr1.moveDegreesCCW (1);
    stepperr3.moveDegreesCCW(1);
  }

  delay(3000);

  digitalWrite(normaldir, LOW);  
  for (int x = 0; x < 1350; x++) {
    digitalWrite(normalstep, HIGH);
    delayMicroseconds(700);
    digitalWrite(normalstep, LOW);
    delayMicroseconds(700);
  }

    delay (1000);
    stepperr3.moveDegreesCCW(100);
    delay (1000);
    stepperr3.moveDegreesCW(50);
    delay (1000);
    stepperr3.moveDegreesCCW(54);
  
  delay(2000);
    
  digitalWrite(normaldir, HIGH);  
  for (int x = 0; x < 1350; x++) {
    digitalWrite(normalstep, HIGH);
    delayMicroseconds(700);
    digitalWrite(normalstep, LOW);
    delayMicroseconds(700);
  }
  delay (2000);
  
  
}