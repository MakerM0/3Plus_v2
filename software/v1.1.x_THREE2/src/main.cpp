
#include "board_def.h"
#include "manager/manager.h"
#include "app/app_key.h"
#include "app/app_pc.h"
#include "app/app_weather.h"

void setup()
{
	
	Serial.begin(115200);

	// while (!Serial);

	board_init();
	app_key_init();
	manager_init();
}

void loop()
{
	manager_loop();
}



// /*******************************************************************************
//  * Start of Arduino_GFX setting
//  * 
//  * Arduino_GFX try to find the settings depends on selected board in Arduino IDE
//  * Or you can define the display dev kit not in the board list
//  * Defalult pin list for non display dev kit:
//  * Arduino Nano, Micro and more: CS:  9, DC:  8, RST:  7, BL:  6, SCK: 13, MOSI: 11, MISO: 12
//  * ESP32 various dev board     : CS:  5, DC: 27, RST: 33, BL: 22, SCK: 18, MOSI: 23, MISO: nil
//  * ESP32-C3 various dev board  : CS:  7, DC:  2, RST:  1, BL:  3, SCK:  4, MOSI:  6, MISO: nil
//  * ESP32-S2 various dev board  : CS: 34, DC: 35, RST: 33, BL: 21, SCK: 36, MOSI: 35, MISO: nil
//  * ESP32-S3 various dev board  : CS: 40, DC: 41, RST: 42, BL: 48, SCK: 36, MOSI: 35, MISO: nil
//  * ESP8266 various dev board   : CS: 15, DC:  4, RST:  2, BL:  5, SCK: 14, MOSI: 13, MISO: 12
//  * Raspberry Pi Pico dev board : CS: 17, DC: 27, RST: 26, BL: 28, SCK: 18, MOSI: 19, MISO: 16
//  * RTL8720 BW16 old patch core : CS: 18, DC: 17, RST:  2, BL: 23, SCK: 19, MOSI: 21, MISO: 20
//  * RTL8720_BW16 Official core  : CS:  9, DC:  8, RST:  6, BL:  3, SCK: 10, MOSI: 12, MISO: 11
//  * RTL8722 dev board           : CS: 18, DC: 17, RST: 22, BL: 23, SCK: 13, MOSI: 11, MISO: 12
//  * RTL8722_mini dev board      : CS: 12, DC: 14, RST: 15, BL: 13, SCK: 11, MOSI:  9, MISO: 10
//  * Seeeduino XIAO dev board    : CS:  3, DC:  2, RST:  1, BL:  0, SCK:  8, MOSI: 10, MISO:  9
//  * Teensy 4.1 dev board        : CS: 39, DC: 41, RST: 40, BL: 22, SCK: 13, MOSI: 11, MISO: 12
//  ******************************************************************************/
// #include <Arduino_GFX_Library.h>

// #define GFX_BL DF_GFX_BL // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

 

// Arduino_DataBus *bus = new Arduino_ESP32SPI(13 /*dc*/, 39 /*cs*/, 41 /*sclk*/, 40 /*mosi*/,GFX_NOT_DEFINED);

// /* More display class: https://github.com/moononournation/Arduino_GFX/wiki/Display-Class */
// Arduino_GFX *gfxn = new Arduino_GC9A01(bus, -1, 0 /* rotation */, true /* IPS */,128,128);
 

// void setup(void)
// {
//      pinMode(PIN_RST, OUTPUT);
//     digitalWrite(PIN_RST, HIGH);

//      pinMode(PIN_CS2, OUTPUT);
//     digitalWrite(PIN_CS2, HIGH);

// 	     pinMode(PIN_CS3, OUTPUT);
//     digitalWrite(PIN_CS3, HIGH);

//     pinMode(PIN_BL, OUTPUT);
//     digitalWrite(PIN_BL, HIGH);


//     gfxn->begin();
//     gfxn->fillScreen(YELLOW);


 

//     gfxn->setCursor(10, 10);
//     gfxn->setTextColor(RED);
//     gfxn->println("Hello World!");

//     delay(5000); // 5 seconds
// }

// void loop()
// {
//     gfxn->setCursor(random(gfxn->width()), random(gfxn->height()));
//     gfxn->setTextColor(random(0xffff), random(0xffff));
//     gfxn->setTextSize(random(6) /* x scale */, random(6) /* y scale */, random(2) /* pixel_margin */);
//     gfxn->println("Hello World!");

//     delay(1000); // 1 second
// }
