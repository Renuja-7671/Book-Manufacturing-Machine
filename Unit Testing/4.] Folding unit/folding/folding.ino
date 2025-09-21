const int foldingstepPin1 = 28;
const int foldingdirPin1 = 29;
const int wipermotor=30;


void setup() {
  // Sets the two pins as Outputs
  pinMode(foldingstepPin1, OUTPUT);
  pinMode(foldingdirPin1, OUTPUT);
  pinMode(wipermotor, OUTPUT);
  digitalWrite (wipermotor,HIGH);
  
}


void loop() {
  
  digitalWrite(foldingdirPin1, LOW);  
  for (int x = 0; x < 1500; x++) {
    digitalWrite(foldingstepPin1, HIGH);
    delayMicroseconds(3000);
    digitalWrite(foldingstepPin1, LOW);
    delayMicroseconds(3000);
  }

  delay (500);
  digitalWrite (wipermotor,LOW);
  delay (10000);
  digitalWrite (wipermotor,HIGH);
  delay (500);


  digitalWrite(foldingdirPin1, HIGH);  
  for (int x = 0; x < 1500; x++) {
    digitalWrite(foldingstepPin1, HIGH);
    delayMicroseconds(3000);
    digitalWrite(foldingstepPin1, LOW);
    delayMicroseconds(3000);
  }

    delay(5000);
  
}