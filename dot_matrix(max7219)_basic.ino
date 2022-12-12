#include "LedControl.h"
/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to CS
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

void setup() {
  /* The MAX72XX is in power-saving mode on startup,  we have to do a wakeup call */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

void loop() { 
  lc.setLed(0, 3, 3, HIGH);   // 0번째 연결된 모듈의 (3,3)위치의 LED에 HIGH 출력
  lc.setRow(0, 5, 0xF0);      // 0번째 연결된 모듈의 5번째 Row에 0xF0 출력
  delay(1000);

  lc.setLed(0, 3, 3, LOW);    // 0번째 연결된 모듈의 (3,3) 위치의 LED에 LOW 출력
  lc.setRow(0, 5, 0x00);      // 0번째 연결된 모듈의 5번째 Row에 0x00 출력
  delay(1000);
}

