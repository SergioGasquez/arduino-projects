int Rec = 11;
int Play = 13;

void setup()
{
  pinMode(Rec, OUTPUT);
  pinMode(Play, OUTPUT);
}

void loop()
{
  digitalWrite(Rec, HIGH);
  delay(10000);
  digitalWrite(Rec, LOW);
  delay(5000);
  digitalWrite(Play, HIGH);
  delay(100);
  digitalWrite(Play, LOW);
  delay(10000);
}
