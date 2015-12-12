int buzzerPin = 9;


void setup()
{
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  int duration;
  duration= 1500;
  tone(buzzerPin, 262, duration);
  delay(duration);         
  noTone(duration);
  delay(duration);
}

/*
 * note  frequency
 * c     262 Hz
 * d     294 Hz
 * e     330 Hz
 * f     349 Hz
 * g     392 Hz
 * a     440 Hz
 * b     494 Hz
 * C     523 Hz
 */
