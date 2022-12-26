#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH  128 
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  
#define DHTPIN        D4     
#define DHTTYPE       DHT11

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);
  
void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("OLED(SSD1306) allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  dht.begin();
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humi. : ");Serial.print(h);Serial.print("[%]\t");
  Serial.print("Temp. : ");Serial.print(t);Serial.println("[*C]");

  display.clearDisplay();         // OLED 비디오 메모리 삭제
  display.setCursor(0,0);         // 커서의 위치를 0, 0으로 이동
  display.setTextSize(2);         // 폰트 사이즈 2로 변경
  display.println("Temp&Humi");  // 제목, "Temp&Humi"출력
  
  display.setTextSize(1);         // 폰트 사이즈 1로 변경
  display.setCursor(0,20);        // 커서의 위치 0, 20으로 변경
  display.print("Humi. : ");display.print(h);display.println("[%]");
  display.print("Temp. : ");display.print(t);display.println("[*C]");
  display.display();
  delay(1000);
}
