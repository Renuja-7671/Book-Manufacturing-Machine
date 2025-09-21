const int stepPin = 26;
const int dirPin = 27;

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(40, INPUT);
}
void loop() {
  
  digitalWrite(dirPin,LOW);  
  for (int x = 0; x < 4000; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
  }

  digitalWrite(dirPin, LOW);  
  for (int x = 0; x < 4000; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
  }

  digitalWrite(dirPin, LOW);  
  for (int x = 0; x < 1700; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
  }

  delay(2000);

  digitalWrite(dirPin, HIGH);  
  for (int x = 0; x < 4000; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
  }

  digitalWrite(dirPin, HIGH);  
  for (int x = 0; x < 4000; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
  }

   digitalWrite(dirPin, HIGH);  
  for (int x = 0; x < 2500; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);

    if(position1()){
      break;
    }

  }
  delay(2000);
}

 bool position1() 
{
  return digitalRead(40);
}