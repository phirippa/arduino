#include "DHT.h"
// Phi board v1.0에서 DHT의 데이터 선은 D4에 연결되어 있음.
#define DHTPIN D4     
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");     Serial.print(h);  Serial.print("[%]  ");
  Serial.print("Temperature: ");  Serial.print(t);  Serial.println("[*C]");
}
