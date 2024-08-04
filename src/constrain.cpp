#define POT A0

void setup()
{
  pinMode(POT, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(constrain(analogRead(POT);, 500, 800));
  delay(250);
}