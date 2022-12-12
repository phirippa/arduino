int fndNum[10] = {
 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F
};

void setup() {
  DDRD = 0B11111111;
}

void loop() {
  for(int num = 0; num<11;num++) {
    PORTD = fndNum[num];
  	delay(1000);
  }
}
