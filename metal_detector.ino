#include "LiquidCrystal.h"
LiquidCrystal lcd(10, 9, 8, 7, 6, 5);

const int IRsensor1 = 0;
const int IRsensor2 = 2;
const int metaldetect= 3;
const int motA1 = 12;
const int motA2 = 13;
const int LED = 4;


volatile byte state2 = LOW;
volatile int counter;
volatile byte state3 = LOW;

void setup()
{
 pinMode(IRsensor1,INPUT);
 pinMode(IRsensor2,INPUT);
 pinMode(metaldetect,INPUT);
 pinMode(motA1,OUTPUT);
 pinMode(motA2,OUTPUT);
 pinMode(LED,OUTPUT);
 

 attachInterrupt(digitalPinToInterrupt(IRsensor2),COUNT,CHANGE);
 attachInterrupt(digitalPinToInterrupt(metaldetect),GATE,CHANGE);
 lcd.begin(16,2);
}
void loop()
{
 int sensorval = digitalRead(IRsensor1);
 if(sensorval == HIGH)
 {
  digitalWrite(LED,HIGH);
 }
 else{
  digitalWrite(LED,LOW);
 }
 
}

void COUNT()
{
  state2=!state2;
  if(state2 == HIGH){
  
    counter ++;
  }
  lcd.setCursor(0,1);
  lcd.print("ppl entered=");
  lcd.print(counter);
  }
void GATE()
{
  state3=!state3;
  if(state3 == HIGH)
  {
    digitalWrite(motA1,HIGH);
    digitalWrite(motA2,LOW);
    lcd.setCursor(0,0);
    lcd.print("gate is opening");
  }else
  {
    digitalWrite(motA1,LOW);
    digitalWrite(motA2,HIGH);
     lcd.setCursor(0,0);
    lcd.print("gate is closing");
  }
 
}
