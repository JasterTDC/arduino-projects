#define MIDDLE_MIDDLE 2
#define TOP_LEFT 3
#define TOP 4
#define TOP_RIGHT 5
#define BOTTOM_LEFT 6
#define BOTTOM 7
#define BOTTOM_RIGHT 8
#define BOTTOM_POINT 9

void setup() {
  pinMode(MIDDLE_MIDDLE, OUTPUT);
  pinMode(TOP_LEFT, OUTPUT);
  pinMode(TOP, OUTPUT);
  pinMode(TOP_RIGHT, OUTPUT);
  pinMode(BOTTOM_LEFT, OUTPUT);
  pinMode(BOTTOM, OUTPUT);
  pinMode(BOTTOM_RIGHT, OUTPUT);
  pinMode(BOTTOM_POINT, OUTPUT);
}

void writeOne()
{
  digitalWrite(TOP_RIGHT, HIGH);
  digitalWrite(BOTTOM_RIGHT, HIGH);
  delay(500);
  
}

void writeTwo()
{
  digitalWrite(TOP, HIGH);
  digitalWrite(TOP_RIGHT, HIGH);
  digitalWrite(MIDDLE_MIDDLE, HIGH);
  digitalWrite(BOTTOM_LEFT, HIGH);
  digitalWrite(BOTTOM, HIGH);
  delay(500);
}

void writeThree()
{
  digitalWrite(TOP, HIGH);
  digitalWrite(TOP_RIGHT, HIGH);
  digitalWrite(MIDDLE_MIDDLE, HIGH);
  digitalWrite(BOTTOM_RIGHT, HIGH);
  digitalWrite(BOTTOM, HIGH);
  delay(500);
}

void writeFour()
{
  digitalWrite(TOP_LEFT, HIGH);
  digitalWrite(TOP_RIGHT, HIGH);
  digitalWrite(MIDDLE_MIDDLE, HIGH);
  digitalWrite(BOTTOM_RIGHT, HIGH);
  delay(500);
}

void writeFive()
{
  digitalWrite(TOP, HIGH);
  digitalWrite(TOP_LEFT, HIGH);
  digitalWrite(MIDDLE_MIDDLE, HIGH);
  digitalWrite(BOTTOM_RIGHT, HIGH);
  digitalWrite(BOTTOM, HIGH);
  delay(500);
}

void writeSix()
{
  digitalWrite(TOP, HIGH);
  digitalWrite(TOP_LEFT, HIGH);
  digitalWrite(MIDDLE_MIDDLE, HIGH);
  digitalWrite(BOTTOM_RIGHT, HIGH);
  digitalWrite(BOTTOM, HIGH);
  digitalWrite(BOTTOM_LEFT, HIGH);
  delay(500);
}

void writeSeven()
{
  digitalWrite(TOP, HIGH);
  digitalWrite(TOP_RIGHT, HIGH);
  digitalWrite(BOTTOM_RIGHT, HIGH);
  delay(500);
}

void writeEight()
{
  digitalWrite(TOP, HIGH);
  digitalWrite(TOP_LEFT, HIGH);
  digitalWrite(TOP_RIGHT, HIGH);
  digitalWrite(MIDDLE_MIDDLE, HIGH);
  digitalWrite(BOTTOM_RIGHT, HIGH);
  digitalWrite(BOTTOM, HIGH);
  digitalWrite(BOTTOM_LEFT, HIGH);
  delay(500);
}

void writeNine()
{
  digitalWrite(TOP, HIGH);
  digitalWrite(TOP_LEFT, HIGH);
  digitalWrite(TOP_RIGHT, HIGH);
  digitalWrite(MIDDLE_MIDDLE, HIGH);
  digitalWrite(BOTTOM_RIGHT, HIGH);
  delay(500);
}

void writePoint()
{
  digitalWrite(BOTTOM_POINT, HIGH);
  delay(500);
}

void flushDigital(bool flushPoint = false)
{
  digitalWrite(TOP_LEFT, LOW);
  digitalWrite(TOP, LOW);
  digitalWrite(TOP_RIGHT, LOW);
  digitalWrite(MIDDLE_MIDDLE, LOW);
  digitalWrite(BOTTOM_LEFT, LOW);
  digitalWrite(BOTTOM, LOW);
  digitalWrite(BOTTOM_RIGHT, LOW);

  if (flushPoint) {
    digitalWrite(BOTTOM_POINT, LOW);
  }

  delay(300);
}

void loop() 
{
  writePoint();
  writeOne();
  flushDigital();
  writeTwo();
  flushDigital();
  writeThree();
  flushDigital();
  writeFour();
  flushDigital();
  writeFive();
  flushDigital();
  writeSix();
  flushDigital();
  writeSeven();
  flushDigital();
  writeEight();
  flushDigital();
  writeNine();
  flushDigital();
  writePoint();
  flushDigital(true);
}
