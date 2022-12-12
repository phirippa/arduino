#define segA 0
#define segB 1
#define segC 2
#define segD 3
#define segE 4
#define segF 5
#define segG 6
#define segDp 7

int fndPin[8] = {segA, segB, segC, segD, segE, segF, segG, segDp};

int fndNum[10] = {
 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F
};

void fnd_display(int num){
  for(int bit = 0; bit < 8; bit++) {
    digitalWrite(fndPin[bit], bitRead(fndNum[num], bit));
  }
}

void setup() {
  for(int i = 0; i < 8; i++){
    pinMode(fndPin[i], OUTPUT);
    digitalWrite(fndPin[i], LOW);  // all segment off
  }
}

void loop() {
  for(int num = 0; num <10; num++){
    fnd_display(num);
    delay(1000);
  }
}


