#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22
#define LEDPIN 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
  Serial.println("ESP32 + DHT22 + LED READY!");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("TEMPERATURE: ");
  Serial.print(temp);
  Serial.print(" °C  |  HUMIDITY: ");
  Serial.println(hum);

  if (temp > 30) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }

  delay(2000);
}

