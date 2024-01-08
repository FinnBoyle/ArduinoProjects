#include <LedControl.h>
#define CONF_BUTTON 7
#define LEFT_BUTTON 4
#define RIGHT_BUTTON 2

// Led Matrix setup
int DIN = 12;
int CS = 10;
int CLK = 11;

LedControl lc = LedControl(DIN, CLK, CS, 0);

//letter and number storage
const int STORAGE_SIZE = 37;
byte alphanumerics[STORAGE_SIZE][8] = {
  { // space/blank
    B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
  }, { // letter A
    B00000000, B00011000, B00100100, B01000010, B01111110, B01000010, B01000010, B00000000
  }, { // letter B
    B00000000, B01111000, B01000100, B01111000, B01111000, B01000100, B01111000, B00000000
  }, { // letter C
    B00000000, B01111110, B01000000, B01000000, B01000000, B01000000, B01111110, B00000000
  }, { // letter D
    B00000000, B01111000, B01000100, B01000010, B01000010, B01000100, B01111000, B00000000
  }, { // letter E
    B00000000, B01111110, B01000000, B01111110, B01000000, B01000000, B01111110, B00000000
  }, { // letter F
    B00000000, B01111110, B01000000, B01111110, B01000000, B01000000, B01000000, B00000000
  }, { // letter G
    B00000000, B00111110, B01000000, B01000000, B01001110, B01000100, B00111100, B00000000
  }, { // letter H
    B00000000, B01000010, B01000010, B01111110, B01000010, B01000010, B01000010, B00000000
  }, { // letter I
    B00000000, B01111110, B00010000, B00010000, B00010000, B00010000, B01111110, B00000000
  }, { // letter J
    B00000000, B00111110, B00001000, B00001000, B01001000, B01001000, B00110000, B00000000
  }, { // letter K
    B00000000, B01001000, B01010000, B01100000, B01100000, B01010000, B01001000, B00000000
  }, { // letter L
    B00000000, B01000000, B01000000, B01000000, B01000000, B01000000, B01111110, B00000000
  }, { // letter M
    B00000000, B01000010, B01100110, B01011010, B01000010, B01000010, B01000010, B00000000
  }, { // letter N
    B00000000, B01000010, B01100010, B01010010, B01001010, B01000110, B01000010, B00000000
  }, { // letter O
    B00000000, B00111100, B01000010, B01000010, B01000010, B01000010, B00111100, B00000000
  }, { // letter P
    B00000000, B01111100, B01000010, B01111100, B01000000, B01000000, B01000000, B00000000
  }, { // letter Q
    B00000000, B00111100, B01000010, B01000010, B01001010, B00111100, B00001000, B00000000
  }, { // letter R
    B00000000, B01111100, B01000010, B01111100, B01010000, B01001000, B01000100, B00000000
  }, { // letter S
    B00000000, B00111110, B01000000, B01000000, B00111100, B00000010, B01111100, B00000000
  }, { // letter T
    B00000000, B01111110, B00010000, B00010000, B00010000, B00010000, B00010000, B00000000
  }, { // letter U
    B00000000, B01000010, B01000010, B01000010, B01000010, B01000010, B00111100, B00000000
  }, { // letter V
    B00000000, B01000010, B01000010, B01000010, B01000010, B00100100, B00011000, B00000000
  }, { // letter W
    B00000000, B01000010, B01000010, B01000010, B01011010, B01100110, B01000010, B00000000
  }, { // letter X
    B00000000, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B00000000
  }, { // letter Y
    B00000000, B01000010, B00100100, B00011000, B00010000, B00100000, B01000000, B00000000
  }, { // letter Z
    B00000000, B01111110, B00000100, B00001000, B00010000, B00100000, B01111110, B00000000
  }, { // number 0
    B00000000, B00011000, B00100100, B01000010, B01000010, B00100100, B00011000, B00000000
  }, { // number 1
    B00000000, B00001000, B00011000, B00101000, B00001000, B00001000, B01111110, B00000000
  }, { // number 2
    B00000000, B01111100, B00000010, B00000100, B00011000, B00100000, B01111110, B00000000
  }, { // number 3
    B00000000, B01111100, B00000010, B00000010, B01111100, B00000010, B01111100, B00000000
  }, { // number 4
    B00000000, B01000010, B01000010, B01000010, B00111110, B00000010, B00000010, B00000000
  }, { // number 5
    B00000000, B01111110, B01000000, B01111100, B00000010, B00000010, B01111100, B00000000
  }, { // number 6
    B00000000, B00111110, B01000000, B01111100, B01000010, B01000010, B00111100, B00000000
  }, { // number 7
    B00000000, B01111110, B00000100, B00001000, B00010000, B00100000, B01000000, B00000000
  }, { // number 8
    B00000000, B00111100, B01000010, B00111100, B01000010, B01000010, B00111100, B00000000
  }, { // number 9
    B00000000, B00111100, B01000010, B01000010, B00111110, B00000010, B00000010, B00000000
  }
};

void setup() {
  // put your setup code here, to run once:
  // fill in the letters array later?
  Serial.begin(9600);
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  pinMode(CONF_BUTTON, INPUT_PULLUP);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
}

int i = 0;
int j = 0;
const int MAX = 7;
const int MIN = 0;

void loop() {
  /*if(digitalRead(CONF_BUTTON) == 0) {
    //increment vertical 'j' value. If at maximum, reset to minimum
    j = (j + 1) % (MAX + 1);
  } else if (digitalRead(LEFT_BUTTON) == 0) {
    //increment the horizontal 'i' value. If at maximum, increment vertical 'j' instead
    i = (i + 1) % (MAX + 1);
    if (i == MIN) j = (j + 1) % (MAX + 1);
  } else if (digitalRead(RIGHT_BUTTON) == 0) {
    //decrement the horizontal 'i' value. If at minimum, decrement vertical 'j' instead
    i = (i - 1 + (MAX + 1)) % (MAX + 1);
    if (i == MAX) j = (j - 1 + (MAX + 1)) % (MAX + 1);
  }
  lc.setLed(0, i, j, true);
  lc.setLed(0, i, j, false);
  delay(100);
  */
  int count = 0;
  while (count < STORAGE_SIZE) {
    for (int row=0; row<8; row++) {
      lc.setRow(0, row, alphanumerics[count][row]);
    }
    count++;
    delay(100);
    lc.clearDisplay(0);
    delay(100);
  }
}
