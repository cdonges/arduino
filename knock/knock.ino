#include <LiquidCrystal.h>

int piezo = 10;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(piezo, OUTPUT);

  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  lcd.print("test");
}
