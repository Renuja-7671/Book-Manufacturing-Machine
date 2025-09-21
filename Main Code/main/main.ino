#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <CheapStepper.h>


LiquidCrystal_I2C lcd(0x27,16,2);

byte rowPins[4] = {31,32,33,34};
byte colPins[4] = {35,36,37,38};

char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

Keypad numpad = Keypad(makeKeymap(keys),rowPins,colPins,4,4);

//char key=numpad.getKey();

CheapStepper stepperr1 (4,5,6,7);
CheapStepper stepperr3 (16,17,18,19); 




const int normalstep = 10;
const int normaldir = 11;

const int staplerCW=24;
const int staplerCCW=25;

const int stepPin = 26;
const int dirPin = 27;

const int foldingstepPin1 = 28;
const int foldingdirPin1 = 29;
const int wipermotor = 30;

const int buzzpin = 44;

#define max 10




void setup() {
  
  stepperr1.setRpm(13);
  stepperr3.setRpm(13);
  
  pinMode(normalstep, OUTPUT);
  pinMode(normaldir, OUTPUT);  
  
  pinMode(staplerCW, OUTPUT);
  pinMode(staplerCCW, OUTPUT);
  
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  pinMode(foldingstepPin1, OUTPUT);
  pinMode(foldingdirPin1, OUTPUT);
  pinMode(wipermotor, OUTPUT);
  pinMode(buzzpin, OUTPUT);

  pinMode(39, INPUT);
  pinMode(40, INPUT);
  pinMode(41, INPUT);

  digitalWrite (wipermotor,HIGH);

  lcd.init();
  lcd.backlight();

}

void loop() {

  msg1("!!HELLO!!");
  delay (3000);

  msg1("Press A to start.");

  char key=numpad.getKey();

  while (true) {
    key=numpad.getKey();
    if (key)
      break; 
  }

  
  if(key == 'A')
  {
    msg1("Process starting");
    delay (3000);
    if(normalIR())
    {
      msg1("Papers are ");
      msg2("there|Cutting!");

      if(position1()){

        cutterNormal();

        msg1("Stapling ");

        staple();
      
        msg1("Tray moving");
        msg2("forward ");
      
        trayFoward();

        msg1("Book is folding");

        foldingUnit();

        msg1("Tray moving back");

        trayBackward();

        if(finalIR())
        {
          lcd.clear();
          lcd.setCursor(6,0);
          lcd.print("|*_*|");
          msg2("Book Finished");

          for(int y=0;y<3;y++)
          {
          digitalWrite(buzzpin , HIGH);
          delay (2000);
          digitalWrite(buzzpin, LOW);
          delay (2000);
          }
        }else
          {
            error("Error in", "folding unit!");
          }
      }else
        {
          error("Error in tray" , "position!");
          trayBackward();
        }
      }else
      {
        error("No Papers!", " ");
      }

  }else
    {
    msg1("INVALID BUTTON!");
    msg2("Press A");

    for(int y=0;y<2;y++)
          {
          digitalWrite(buzzpin , HIGH);
          delay (500);
          digitalWrite(buzzpin, LOW);
          delay (500);
          }
    delay (2000);
    lcd.clear();
    }
  
}

void cutterNormal()
{ 
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

 //For the rest of the papers

  for(int x=0;x<4;x++)
  {

  stepperr1.moveDegreesCCW (1760);
  stepperr3.moveDegreesCCW (270);
  
  delay (1000);

  for(int z=0;z<80;z++)
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
    stepperr3.moveDegreesCCW(130);
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


}

void staple()
{
  digitalWrite(staplerCW, HIGH);
  delay (7150);
  digitalWrite(staplerCW, LOW);
  delay (2500);
  digitalWrite(staplerCCW, HIGH);
  delay (7150);
  digitalWrite(staplerCCW, LOW);
  delay (2500);
}

void trayFoward()
{
  digitalWrite(dirPin, LOW);  
  for (int x = 0; x < 10; x++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
  }
  digitalWrite(dirPin, LOW);  
  for (int x = 0; x < 4000; x++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
  }

  digitalWrite(dirPin, LOW);  
  for (int x = 0; x < 4000; x++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
  }

  digitalWrite(dirPin, LOW);  
  for (int x = 0; x < 1850; x++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
  }
}

void trayBackward(){

  digitalWrite(dirPin, HIGH);  
  for (int x = 0; x < 4000; x++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);

    if(position1()){
      break;
    }
  }

  digitalWrite(dirPin, HIGH);  
  for (int x = 0; x < 4000; x++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);

    if(position1()){
      break;
    }
  }

   digitalWrite(dirPin, HIGH);  
  for (int x = 0; x < 2500; x++) 
  {
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

void foldingUnit()
{
  digitalWrite(foldingdirPin1, LOW);  
  for (int x = 0; x < 1600; x++) {
    digitalWrite(foldingstepPin1, HIGH);
    delayMicroseconds(3000);
    digitalWrite(foldingstepPin1, LOW);
    delayMicroseconds(3000);
  }

  delay (500);
  digitalWrite (wipermotor,LOW);
  delay (8000);
  digitalWrite (wipermotor,HIGH);
  delay (500);

  digitalWrite(foldingdirPin1, HIGH);  
  for (int x = 0; x < 1600; x++) {
    digitalWrite(foldingstepPin1, HIGH);
    delayMicroseconds(3000);
    digitalWrite(foldingstepPin1, LOW);
    delayMicroseconds(3000);
  }

    delay(5000);
}

                                //Error message

void error(String msg, String line2)
{
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(msg);
  lcd.setCursor(0,1);
  lcd.print(line2);

  for(int y=0; y<5; y++){
    digitalWrite(buzzpin, HIGH);
    delay (500);
    digitalWrite(buzzpin, LOW);
    delay (500);
  }

  delay (10000);

  lcd.clear();

}

void msg1(String message1)
{
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(message1);
}

void msg2(String message2)
{
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print(message2);
}

                                //Error message

bool normalIR() 
{
  return !digitalRead(39);
}

bool position1() 
{
  return digitalRead(40);
}

bool finalIR() 
{
  return !digitalRead(41);
}


