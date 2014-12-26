int redLedPin = 9;
int greenLedPin = 10;
int blueLedPin = 11;

int oldBlue = 0;
int oldGreen = 0;
int oldRed = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop()  {
  int newBlue = random(0, 255);
  int newGreen = random(0, 255);
  int newRed = random(0, 255);
  
  for (int i = 0; i < 50; i++)
  {
    analogWrite(blueLedPin, oldBlue + (newBlue-oldBlue)/50.0*i);
    analogWrite(greenLedPin,  oldGreen + (newGreen-oldGreen)/50.0*i);
    analogWrite(redLedPin,  oldRed + (newRed-oldRed)/50.0*i);
    delay(50);
  }
  
    delay(50);
  oldBlue = newBlue;
  oldGreen = newGreen;
  oldRed = newRed;
}
