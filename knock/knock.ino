#include <LiquidCrystal.h>

#define KNOCKS 10

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int threshhold = 50;
int gapWait = 500;

unsigned long startTime = -1;
unsigned long lastHit = -1;

int knocks[KNOCKS];
int pos = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  int knock = analogRead(0);
  if (knock > threshhold && pos < KNOCKS)
  {
    if (startTime == -1)
    {
      startTime = millis();
    }
   
     if ((lastHit + gapWait) < millis()) 
     {
      lcd.clear();
      lcd.print(knock);
      lastHit = millis();
      knocks[pos] = knock;
      pos++;
     }
   }
}
