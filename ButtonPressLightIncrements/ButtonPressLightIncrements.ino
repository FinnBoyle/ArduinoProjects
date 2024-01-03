#include <LedControl.h>
#define BUTTON_PIN 8

int DIN = 2;
int CS = 3;
int CLK = 4;


LedControl lc = LedControl(DIN, CLK, CS, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

int i = 0;
int j = 0;
bool onoff = true;

void loop() {
  if(digitalRead(BUTTON_PIN) == 0) {
    //increment LED target (col)
    i++;
    if(i > 7) {
      // reset LED target (col) and increment LED target (row)
      i=0;
      j++;
      if (j > 7) {
        // reset LED target (row) and switch to start turning off/on LEDs 
        j = 0;
        onoff = !onoff;
      }
    }
  }
  lc.setLed(0, i, j, onoff);
  delay(50);
}
