#define RED_LED 10
#define MAX_LIGHT 16
#define MIN_LIGHT 0
#define DURATION 100

int i;

void setup() {
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  i = MIN_LIGHT;
  while (i < MAX_LIGHT) {
    analogWrite(RED_LED, i);
    delay(DURATION);
    i++;
  }
  while (i > MIN_LIGHT) {
    analogWrite(RED_LED, i);
    delay(DURATION);
    i--;
  }
}