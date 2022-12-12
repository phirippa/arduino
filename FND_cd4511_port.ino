int digit[10] ={
  0x00,		// 0000 0000
  0x10,		// 0001	0000	
  0x20,		// 0010 0000
  0x30,		// 0011 0000
  0x40,		// 0100 0000
  0x50,		// 0101 0000
  0x60,		// 0110 0000
  0x70,		// 0111 0000
  0x80,		// 1000 0000
  0x90		// 1001 0000
};
   
void setup(){
  DDRD = DDRD | 0xF0;
}

void loop() {
  for(int num = 0; num <10; num++) {
  	PORTD = (PORTD & 0x0F) | digit[num];
    delay(1000);
  }
}