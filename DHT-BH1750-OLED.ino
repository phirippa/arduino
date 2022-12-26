#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include <BH1750.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH  128 
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  
#define DHTPIN        D4     
#define DHTTYPE       DHT11

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,                            
                                    &Wire, OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter;
  
void setup() {
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  
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
  float lux = lightMeter.readLightLevel();
  Serial.print("Humi.: ");Serial.print(h);Serial.print("[%]\t");
  Serial.print("Temp.: ");Serial.print(t);Serial.print("[*C]\t");
  Serial.print("Lux. : ");Serial.print(lux);Serial.println("[L]");
  
  display.clearDisplay();         // OLED 비디오 메모리 삭제
  display.setCursor(0,0);         // 커서의 위치를 0, 0으로 이동
  display.println("Sensor Value\n");  // 제목, “Sensor Value"출력
  display.print("Humi.: ");display.print(h);display.println("[%]");
  display.print("Temp.: ");display.print(t);display.println("[*C]");
  display.print("Lux. : ");display.print(lux);display.println("[L]");
  display.display();
  delay(1000);
}
