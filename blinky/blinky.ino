int cols[] = {8, 9, 10, 11};
int rows[] = {12, 13};

int display[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

void setup() {
  for (int i = 0; i < 4; i++)
  {
    pinMode(cols[i], OUTPUT);
  }

  for (int i = 0; i < 2; i++)
  {
    pinMode(rows[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++)
  {
    Clear();
    display[0][i] = 1;
    display[1][3 - i] = 1;
    Write(200);
  }

  for (int i = 0; i < 4; i++)
  {
    Clear();
    display[0][3 - i] = 1;
    display[1][i] = 1;
    Write(200);
  }
}

void Clear()
{
  for (int i = 0; i < 4; i++)
  {
    display[0][i] = 0;
    display[1][i] = 0;
  }
}

void Write(int ms)
{
  int startTime = millis();

  while (millis() - startTime <= ms)
  {
    for (int row = 0; row < 2; row++)
    {
      digitalWrite(rows[row == 0 ? 1 : 0], HIGH);
      for (int col = 0; col < 4; col++)
      {
        if (display[row][col] == 1)
        {
          digitalWrite(cols[col], HIGH);
        }
        else
        {
          digitalWrite(cols[col], LOW);
        }
      }
      digitalWrite(rows[row], LOW);
      delay(10);
    }
  }
}
