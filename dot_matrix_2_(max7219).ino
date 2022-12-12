#include "LedControl.h"

LedControl matrix = LedControl(12,11,10,2);

byte heart[] = {  B01100110,
                  B11111111,
                  B11111111,
                  B11111111,
                  B01111110,
                  B00111100,
                  B00011000,
                  B00000000 };

void display_heart(int address) {
  if (address >= 0 && address < 2) {
    for(int row = 0; row<8; row++ ) {
      matrix.setRow(address, row, heart[row]);
    }
  }
}

void setup() {
  matrix.shutdown(0,false);
  matrix.shutdown(1,false);

  matrix.setIntensity(0, 3);
  matrix.setIntensity(1, 3);
  
  matrix.clearDisplay(0);
  matrix.clearDisplay(1);
}

void loop() { 
  matrix.clearDisplay(1);
  display_heart(0);
  delay(500);
  
  matrix.clearDisplay(0);
  display_heart(1);
  delay(500);
}

