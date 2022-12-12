#define	segA	12
#define segB	11
#define segC	10
#define	segD	9
#define segE	8
#define segF	7
#define segG	6
#define	segDp	5

int fndPin[8] = {segDp, segG, segF, segE, segD, segC, segB, segA};

int fndNum[17][8] = {
//Dp, g, f, e, d, c, b, a
  {1, 1, 0, 0, 0, 0, 0, 0}, // 0, 0xC0
  {1, 1, 1, 1, 1, 0, 0, 1}, // 1, 0xF9
  {1, 0, 1, 0, 0, 1, 0, 0}, // 2, 0xA4
  {1, 0, 1, 1, 0, 0, 0, 0}, // 3, 0xB0
  {1, 0, 0, 1, 1, 0, 0, 1}, // 4, 0x99
  {1, 0, 0, 1, 0, 0, 1, 0}, // 5, 0x92
  {1, 0, 0, 0, 0, 0, 1, 0}, // 6, 0x82
  {1, 1, 1, 1, 1, 0, 0, 0}, // 7, 0xF8
  {1, 0, 0, 0, 0, 0, 0, 0}, // 8, 0x80
  {1, 0, 0, 1, 1, 0, 0, 0}, // 9, 0x98
  {1, 0, 0, 0, 1, 0, 0, 0},	// 10(0x0A), 0x88
  {1, 0, 0, 0, 0, 0, 1, 1}, // 11(0x0B), 0x83
  {1, 1, 0, 0, 0, 1, 1, 0}, // 12(0x0C), 0xC6
  {1, 0, 1, 0, 0, 0, 0, 1}, // 13(0x0D), 0xA1
  {1, 0, 0, 0, 0, 1, 1, 0}, // 14(0x0E), 0x86
  {1, 0, 0, 0, 1, 1, 1, 0}, // 15(0x0F), 0x8E
  {1, 1, 1, 1, 1, 1, 1, 1} // Blank,     0xFF
};

void setup()	
{
  for(int i = 0; i < 8;  i++){
    pinMode(fndPin[i], OUTPUT);
    digitalWrite(fndPin[i], HIGH);
  }
}

void loop()
{
  for(int num = 0; num <10; num++){
    for(int i = 0; i<8; i++) {
      digitalWrite(fndPin[i], fndNum[num][i]);
    }
    delay(1000);
  }
}
