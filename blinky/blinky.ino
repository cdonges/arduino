int cols[] = {8,9,10,11};
int rows[] = {12,13};

int display[2][4] = {{0,1,1,1},{1,1,0,1}};

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
  Write();
}

void Write()
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
