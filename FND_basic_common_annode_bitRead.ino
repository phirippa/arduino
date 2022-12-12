#define	segA	12
#define segB	11
#define segC	10
#define	segD	9
#define segE	8
#define segF	7
#define segG	6
#define	segDp	5

//int fndPin[8] = {segDp, segG, segF, segE, segD, segC, segB, segA};
int fndPin[8] = {segA, segB, segC, segD, segE, segF, segG, segDp};

    
int fndNum[17] = { 
  // 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  
  0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x98
};

void fnd_display(int num){
  for(int bit = 0; bit < 8; bit++) {
    digitalWrite(fndPin[bit], bitRead(fndNum[num], bit));
  }
}

void setup(){
  for(int i = 0; i < 8;  i++){
    pinMode(fndPin[i], OUTPUT);
    digitalWrite(fndPin[i], HIGH);
  }
}

void loop() {
  for(int num = 0; num <10; num++){
    fnd_display(num);
    delay(1000);
  }
}

