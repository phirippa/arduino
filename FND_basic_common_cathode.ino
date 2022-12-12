#define segA 0
#define segB 1
#define segC 2
#define segD 3
#define segE 4
#define segF 5
#define segG 6
#define segDp 7

//int fndPin[8] = {segDp, segG, segF, segE, segD, segC, segB, segA};
int fndPin[8] = {segA, segB, segC, segD, segE, segF, segG, segDp};

int fndNum[10][8] = {
//Dp, g, f, e, d, c, b, a
 {0, 0, 1, 1, 1, 1, 1, 1}, // 0, 0x3F
 {0, 0, 0, 0, 0, 1, 1, 0}, // 1, 0x06
 {0, 1, 0, 1, 1, 0, 1, 1}, // 2, 0x5B
 {0, 1, 0, 0, 1, 1, 1, 1}, // 3, 0x4F
 {0, 1, 1, 0, 0, 1, 1, 0}, // 4, 0x66
 {0, 1, 1, 0, 1, 1, 0, 1}, // 5, 0x6D
 {0, 1, 1, 1, 1, 1, 0, 1}, // 6, 0x7D
 {0, 0, 1, 0, 0, 1, 1, 1}, // 7, 0x27
 {0, 1, 1, 1, 1, 1, 1, 1}, // 8, 0x7F
 {0, 1, 1, 0, 1, 1, 1, 1}  // 9, 0x6F
};

void setup() {
  for(int i = 0; i < 8; i++){
    pinMode(fndPin[i], OUTPUT);
    digitalWrite(fndPin[i], LOW);  // all segment off
  }
}

void loop() {
  for(int num = 0; num <10; num++){
    for(int i = 0; i<8; i++) {
      digitalWrite(fndPin[i], fndNum[num][i]);
    }
    delay(1000);
  }
}
