#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define echoPin 7
#define trigPin 8

#define greenPin 9
#define redPin 10

#define setButton 13

int warningDistance = 10;

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  pinMode(setButton, INPUT);

  EEPROM.get(0, warningDistance);

  if (warningDistance > 1000 || warningDistance <= 0)
  {
    warningDistance = 10;
    EEPROM.put(0, warningDistance);
  }
}

void loop()
{
  long duration, distance; // Duration used to calculate distance

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration / 58.2;

  if (digitalRead(setButton) == HIGH)
  {
    warningDistance = distance;
    EEPROM.put(0, warningDistance);
  }
  else
  {
    digitalWrite(greenPin, distance < warningDistance ? LOW : HIGH);
    digitalWrite(redPin, distance < warningDistance ? HIGH : LOW);

    lcd.clear();
    lcd.print(distance);
  }
  delay(500);
}


