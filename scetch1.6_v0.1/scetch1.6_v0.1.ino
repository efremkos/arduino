#include <SPI.h>
#include <LoRa.h>
#include "board_def.h"
#include <WiFi.h>
#include <SD.h>

OLED_CLASS_OBJ display(OLED_ADDRESS, OLED_SDA, OLED_SCL);

#define WIFI_SSID       "NewHouse"
#define WIFI_PASSWORD   "01012021"





void setup()
{
  Serial.begin(115200);
  while (!Serial);

  display.init();
  display.flipScreenVertically();
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_CENTER);

  display.drawString(display.getWidth() / 2, display.getHeight() / 2, "Slavnie vorota");
  display.display();
  delay(3000);
  
  display.clear();  
  display.drawString(display.getWidth() / 2, display.getHeight() / 2, LORA_SENDER ? "LoRa Sender" : "LoRa Receiver");
  display.display();
  delay(2000);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    display.clear();
    Serial.println("WiFi Connect Fail");
    display.drawString(display.getWidth() / 2, display.getHeight() / 2, "WiFi Connect Fail");
    display.display();
    delay(2000);
    esp_restart();
  }
  Serial.print("Connected : ");
  Serial.println(WiFi.SSID());
  Serial.print("IP:");
  Serial.println(WiFi.localIP().toString());
  display.clear();
  display.drawString(display.getWidth() / 2, display.getHeight() / 2, "IP:" + WiFi.localIP().toString());
  display.display();
  delay(2000);
  
  // LoRa инициализируется
  SPI.begin(CONFIG_CLK, CONFIG_MISO, CONFIG_MOSI, CONFIG_NSS);
  LoRa.setPins(CONFIG_NSS, CONFIG_RST, CONFIG_DIO0);
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  
  
  if (!LORA_SENDER) {  
    // если LoRa приёмник
    display.clear();
    display.drawString(display.getWidth() / 2, display.getHeight() / 2, "LoraRecv Ready");
    display.display();
  }
  
  // запрос текущего ядра процессора
  Serial.println("Core ID setup: "); 
  Serial.println(xPortGetCoreID());
}

int count = 0;





void loop()
{

  Serial.println("Core ID loop: ");
  Serial.println(xPortGetCoreID()); // запрос ядра процессора

#if LORA_SENDER
  // если LoRa передатчик
  int32_t rssi;
  if (WiFi.status() == WL_CONNECTED) {
    rssi = WiFi.RSSI();
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(display.getWidth() / 2, display.getHeight() / 2, "Send RSSI:" + String(rssi));
    display.display();
    LoRa.beginPacket();
    LoRa.print("WiFi RSSI: ");
    LoRa.print(rssi);
    LoRa.endPacket();
  } else {
    Serial.println("WiFi Connect lost ...");
  }
  delay(2500);
#else
  if (LoRa.parsePacket()) {
    String recv = "";
    while (LoRa.available()) {
      recv += (char)LoRa.read();
    }
    count++;
    display.clear();
    display.drawString(display.getWidth() / 2, display.getHeight() / 2, recv);
    String info = "[" + String(count) + "]" + "RSSI " + String(LoRa.packetRssi());
    display.drawString(display.getWidth() / 2, display.getHeight() / 2 - 16, info);
    display.display();
  }

#endif
}
