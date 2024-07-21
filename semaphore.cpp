#define BLUE_LED 8
#define YELLOW_LED 9
#define RED_LED 10

void call_red(int duration_in_ms) {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  delay(duration_in_ms);
}

void call_yellow(int duration_in_ms) {
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  delay(duration_in_ms);
}

void call_blue(int duration_in_ms) {
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  delay(duration_in_ms);
}

void semaphore() {
  call_red(5000);
  call_blue(5000);
  call_yellow(1500);
}

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop() {
  semaphore();
}
