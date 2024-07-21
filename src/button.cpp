#define RED_LED 4
#define BUTTON 3

int pressed_button = 0;
int released_button = 0;

void switch_led() {
  if (digitalRead(RED_LED) == HIGH)
    digitalWrite(RED_LED, LOW);
  else
    digitalWrite(RED_LED, HIGH);
}

void keyup() {
  if ((pressed_button == 1) && (released_button == 1)) {
    pressed_button = 0;
    released_button = 0;
    switch_led();
  }
}

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    pressed_button = 1;
    released_button = 0;
  }
  else
    released_button = 1;
  keyup();
}
