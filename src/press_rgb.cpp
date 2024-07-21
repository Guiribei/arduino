#define RED_LED 2
#define GREEN_LED 3
#define BLUE_LED 4
#define BUTTON 7
#define MAX_COLORS 3

class Button {

  private:

    int _pressed_button;
    int _released_button;
    int _pin;

  public:

    Button(int pin) : _pin(pin) {
      this->_pressed_button = 0;
      this->_released_button = 0;
  }

    bool press() {
      if (digitalRead(this->_pin) == HIGH) {
        this->_pressed_button = 1;
        this->_released_button = 0;
      }
      else
        this->_released_button = 1;
      if ((this->_pressed_button == 1) && (this->_released_button == 1)) {
        this->_pressed_button = 0;
        this->_released_button = 0;
        return true;
      }
      else
        return false;
    }
};

class Color {
  private:

  int _pin_r;
  int _pin_g;
  int _pin_b;
  int _cycle;
  int _number_of_colors;

  void set_color(int red, int green, int blue) {
    digitalWrite(this->_pin_r, red);
    digitalWrite(this->_pin_g, green);
    digitalWrite(this->_pin_b, blue);
  }

  public:

  Color(int pr, int pg, int pb): _pin_r(pr), _pin_g(pg), _pin_b(pb) {
    this->_cycle = 0;
    this->_number_of_colors = MAX_COLORS;
  }

  void change_led_color() {
    if (this->_cycle == 0)
      set_color(1,0,0);
    else if (this->_cycle == 1)
      set_color(0,1,0);
    else if (this->_cycle == 2)
      set_color(0,0,1);
    this->_cycle++;
    if (this->_cycle >= this->_number_of_colors)
      this->_cycle = 0;
  }
};

Button btn(BUTTON);
Color color(RED_LED, GREEN_LED, BLUE_LED);

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if (btn.press())
    color.change_led_color();
}