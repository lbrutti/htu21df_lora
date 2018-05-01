#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

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
// Connect SCL to I2C clock pin (A5 on UNO)
// Connect SDA to I2C data pin (A4 on UNO)

Adafruit_HTU21DF htu = Adafruit_HTU21DF();
SoftwareSerial sensorLoRa(12, 14); //TX, RX 
void setup() {
  WiFi.mode(WIFI_OFF);
//  Serial.begin(115200);
//  Serial.println("HTU21D-F test");
  sensorLoRa.begin(9600);

  if (!htu.begin()) {
//    Serial.println("Couldn't find sensor!");
    while (1);
  }
  //  Serial.print("Temp: "); Serial.print(htu.readTemperature());
//  Serial.print("\t\tHum: "); Serial.println(htu.readHumidity());
  sensorLoRa.print("\tT: "); sensorLoRa.print(htu.readTemperature());
  sensorLoRa.print("\tH: "); sensorLoRa.println(htu.readHumidity());
  ESP.deepSleep(10e6);  

}


void loop() {
}

