#define LDR A0
#define LED 2

int value_ldr;

void setup()
{
  value_ldr = 0;
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  value_ldr = analogRead(LDR);
  if(value_ldr > 400)
    digitalWrite(LED, LOW);
  else
    digitalWrite(LED, HIGH);
  Serial.println(value_ldr);
  delay(100);
}