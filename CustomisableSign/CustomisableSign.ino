#include <LedControl.h>
#define CONF_BUTTON 7
#define LEFT_BUTTON 4
#define RIGHT_BUTTON 2

// Led Matrix setup
int DIN = 12;
int CS = 10;
int CLK = 11;

LedControl lc = LedControl(DIN, CLK, CS, 0);

//letters = []; NEEDS TYPE

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
  // put your main code here, to run repeatedly:
  /*
  lc.setLed(0, 0, 0, true);
  delay(500);
  lc.setLed(0, 0, 0, false);
  delay(500);
  */
  if(digitalRead(CONF_BUTTON) == 0) {
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
}
