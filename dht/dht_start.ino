#include "DHT.h"

#define DHTTYPE DHT22
const int pinDHT = 13; //D7

DHT dht(pinDHT, DHTTYPE);     

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(100);
  Serial.println("Start DHT22 sensor!");
}

void loop() {
  
  delay(2000);

  float humi  = dht.readHumidity();
  float tempC = dht.readTemperature();

  if (isnan(humi) || isnan(tempC)) {
    Serial.println("Failed to read from DHT22 sensor!");
  } else {
    Serial.print("DHT22# Humidity: ");
    Serial.print(humi);
    Serial.print("%");
    Serial.print("  |  "); 
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println("°C");
  }

}
