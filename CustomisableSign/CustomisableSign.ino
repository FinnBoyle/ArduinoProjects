#include <LedControl.h>
#define VRX_PIN A0
#define VRY_PIN A1

// Led Matrix setup
int DIN = 12;
int CS = 10;
int CLK = 11;

LedControl lc = LedControl(DIN, CLK, CS, 0);

// joystick setup
int xRead = 0;
int yRead = 0;

//letters = []; NEEDS TYPE

void setup() {
  // put your setup code here, to run once:
  // fill in the letters array later?
  Serial.begin(9600);
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  //lc.setLed(0, 0, 0, true);

  xRead = analogRead(A0);
  yRead = analogRead(A1);
  Serial.print("this is x: ");
  Serial.println(xRead);
  Serial.print("this is y: ");
  Serial.println(yRead);
  Serial.println();
  delay(2000);
}
