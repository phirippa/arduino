int dataPin[4] ={7, 6, 5, 4};
int digit[10][4] ={
  {0, 0, 0, 0},		// 0
  {0, 0, 0, 1},		// 1		
  {0, 0, 1, 0},		// 2
  {0, 0, 1, 1},		// 3
  {0, 1, 0, 0},		// 4
  {0, 1, 0, 1},		// 5
  {0, 1, 1, 0},		// 6
  {0, 1, 1, 1},		// 7
  {1, 0, 0, 0},		// 8
  {1, 0, 0, 1}		// 9
};
   
void setup(){
  for (int idx = 0; idx < 4; idx++) {
    pinMode(dataPin[idx], OUTPUT);
  } 
}

void loop() {
  for(int num = 0; num<10; num++) {
	displayDigit(num);
    delay(1000);
  }
}

void displayDigit(int num) {
  for(int i = 0; i<4;i++){
    digitalWrite(dataPin[i], digit[num][i]);
  }
}