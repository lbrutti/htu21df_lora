#include <ESP8266WiFi.h>

/*************************************************** 
  This is an example for the HTU21D-F Humidity & Temp Sensor

  Designed specifically to work with the HTU21D-F sensor from Adafruit
  ----> https://www.adafruit.com/products/1899

  These displays use I2C to communicate, 2 pins are required to  
  interface
 ****************************************************/

#include <Wire.h>
#include "Adafruit_HTU21DF.h"

#include <SoftwareSerial.h>


// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin (D1 on NODE MCU)
// Connect SDA to I2C data pin (DA on NODE MCU)

Adafruit_HTU21DF htu = Adafruit_HTU21DF();
SoftwareSerial sensorLoRa(12, 14); //TX, RX 
void setup() {
  WiFi.mode(WIFI_OFF);
  sensorLoRa.begin(9600);

  if (!htu.begin()) {
    while (1);
  }
  sensorLoRa.print("\tT: "); sensorLoRa.print(htu.readTemperature());
  sensorLoRa.print("\tH: "); sensorLoRa.println(htu.readHumidity());
  ESP.deepSleep(60e6);  

}


void loop() {
}

