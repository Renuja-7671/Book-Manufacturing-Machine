#include <CheapStepper.h>

CheapStepper stepperr2 (8,9,10,11);
CheapStepper stepperm2 (16,17,18,19);

void setup() {
  stepperr2.setRpm(13);
  stepperm2.setRpm(13);
  
}

void loop() {
  //Activate only once
  //For paper cutter
  stepperr2.moveDegreesCCW (1800);
  
  
}
