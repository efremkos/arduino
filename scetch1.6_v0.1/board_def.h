#include <Arduino.h>

#define LORA_SENDER 1   // 1=передатчик 0=приёмник

// пины шильда LORA_V1_6_OLED
#include <Wire.h> 
#include "SSD1306Wire.h" 
// дисплей
#define OLED_CLASS_OBJ  SSD1306Wire
#define OLED_ADDRESS    0x3C
#define OLED_SDA    21
#define OLED_SCL    22 
// LoRa
#define CONFIG_MOSI 27
#define CONFIG_MISO 19
#define CONFIG_CLK  5
#define CONFIG_NSS  18
#define CONFIG_RST  23
#define CONFIG_DIO0 26
// SD card 
#define SDCARD_MOSI -1 // 15 временно отключил карту памяти
#define SDCARD_MISO -1 // 2  // -1 нет вывода
#define SDCARD_SCLK -1 // 14
#define SDCARD_CS   -1 // 13

#define BAND 868E6     // lora frequency = 868 МГц 
