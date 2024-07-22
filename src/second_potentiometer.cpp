#define POT A0

int leds[] = {2,3,4,5};

void setup()
{
  int i;

  i = 0;
  while (i < 4) {
    pinMode(leds[i], OUTPUT);
    i++;
  }
  pinMode(POT, INPUT);
}

void turn_lights_on(int x)
{
  int i;

  i = 0;
  while (i < x) {
    digitalWrite(leds[i], HIGH);
    i++;
  }
  i = x;
  while (i < 4) {
    digitalWrite(leds[i], LOW);
    i++;
  }
}

void loop()
{
  turn_lights_on(map(analogRead(POT), 0, 1023, 0, 4));
}