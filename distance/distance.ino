#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define echoPin 7
#define trigPin 8

#define greenPin 9
#define redPin 10

#define buzzer 13

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);

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
  distance = duration/58.2;

  digitalWrite(greenPin, distance < 10 ? LOW : HIGH);
  digitalWrite(redPin, distance < 10 ? HIGH: LOW);

  if (distance < 10)
  {
    tone(buzzer, 1915, 100);
  }


  lcd.clear();
  lcd.print(distance);
  delay(500);
}


