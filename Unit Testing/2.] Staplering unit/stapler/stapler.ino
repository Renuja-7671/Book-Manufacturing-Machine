const int staplerCW=24;
const int staplerCCW=25;


void setup() {
  pinMode(staplerCW, OUTPUT);
  pinMode(staplerCCW, OUTPUT);
}

void loop() {
  digitalWrite(staplerCW, HIGH);
  delay (6900);
  digitalWrite(staplerCW, LOW);
  delay (2000);
  digitalWrite(staplerCCW, HIGH);
  delay (6900);
  digitalWrite(staplerCCW, LOW);
  delay (2000);
  
  }
