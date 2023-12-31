/*
 * start rewrite from:
 * https://github.com/modi12jin/Arduino-ESP32-WEA2012.git
 */
#pragma once

#include "../Arduino_GFX.h"
#include "../Arduino_TFT.h"

#define WEA2012_TFTWIDTH 356  ///< WEA2012 max TFT width
#define WEA2012_TFTHEIGHT 400 ///< WEA2012 max TFT height

#define WEA2012_RST_DELAY 100    ///< delay ms wait for reset finish
#define WEA2012_SLPIN_DELAY 100  ///< delay ms wait for sleep in finish
#define WEA2012_SLPOUT_DELAY 100 ///< delay ms wait for sleep out finish

#define WEA2012_SWRESET 0x01 ///< Software reset register

#define WEA2012_SLPIN 0x10  ///< Enter Sleep Mode
#define WEA2012_SLPOUT 0x11 ///< Sleep Out

#define WEA2012_INVOFF 0x20 ///< Display Inversion OFF
#define WEA2012_INVON 0x21  ///< Display Inversion ON

#define WEA2012_DISPOFF 0x28 ///< Display OFF
#define WEA2012_DISPON 0x29  ///< Display ON

#define WEA2012_CASET 0x2A ///< Column Address Set
#define WEA2012_PASET 0x2B ///< Page Address Set
#define WEA2012_RAMWR 0x2C ///< Memory Write
#define WEA2012_RAMRD 0x2E ///< Memory Read

#define WEA2012_MADCTL 0x36
#define WEA2012_PIXFMT 0x3A // Interface Pixel Format

#define WEA2012_MADCTL_MY 0x80
#define WEA2012_MADCTL_MX 0x40
#define WEA2012_MADCTL_MV 0x20
#define WEA2012_MADCTL_ML 0x10
#define WEA2012_MADCTL_RGB 0x00
#define WEA2012_MADCTL_MH 0x04
#define WEA2012_MADCTL_BGR 0x08

static const uint8_t wea2012_init_operations[] = {
    BEGIN_WRITE,
    //  {cmd, { data }, data_size, delay_ms}
    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x43,
    WRITE_C8_D8, 0x04, 0x70,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x10,
    WRITE_C8_D8, 0x0C, 0x11,
    WRITE_C8_D8, 0x10, 0x02,
    WRITE_C8_D8, 0x11, 0x11,
    WRITE_C8_D8, 0x15, 0x42,
    WRITE_C8_D8, 0x16, 0x11,
    WRITE_C8_D8, 0x1A, 0x02,
    WRITE_C8_D8, 0x1B, 0x11,
    WRITE_C8_D8, 0x61, 0x80,
    WRITE_C8_D8, 0x62, 0x80,
    WRITE_C8_D8, 0x54, 0x44,
    WRITE_C8_D8, 0x58, 0x88,
    WRITE_C8_D8, 0x5C, 0xcc,
    WRITE_C8_D8, 0x20, 0x80,
    WRITE_C8_D8, 0x21, 0x81,
    WRITE_C8_D8, 0x22, 0x31,
    WRITE_C8_D8, 0x23, 0x20,
    WRITE_C8_D8, 0x24, 0x11,
    WRITE_C8_D8, 0x25, 0x11,
    WRITE_C8_D8, 0x26, 0x12,
    WRITE_C8_D8, 0x27, 0x12,
    WRITE_C8_D8, 0x30, 0x80,
    WRITE_C8_D8, 0x31, 0x81,
    WRITE_C8_D8, 0x32, 0x31,
    WRITE_C8_D8, 0x33, 0x20,
    WRITE_C8_D8, 0x34, 0x11,
    WRITE_C8_D8, 0x35, 0x11,
    WRITE_C8_D8, 0x36, 0x12,
    WRITE_C8_D8, 0x37, 0x12,
    WRITE_C8_D8, 0x41, 0x11,
    WRITE_C8_D8, 0x42, 0x22,
    WRITE_C8_D8, 0x43, 0x33,
    WRITE_C8_D8, 0x49, 0x11,
    WRITE_C8_D8, 0x4A, 0x22,
    WRITE_C8_D8, 0x4B, 0x33,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x15,
    WRITE_C8_D8, 0x00, 0x00,
    WRITE_C8_D8, 0x01, 0x00,
    WRITE_C8_D8, 0x02, 0x00,
    WRITE_C8_D8, 0x03, 0x00,
    WRITE_C8_D8, 0x04, 0x10,
    WRITE_C8_D8, 0x05, 0x0C,
    WRITE_C8_D8, 0x06, 0x23,
    WRITE_C8_D8, 0x07, 0x22,
    WRITE_C8_D8, 0x08, 0x21,
    WRITE_C8_D8, 0x09, 0x20,
    WRITE_C8_D8, 0x0A, 0x33,
    WRITE_C8_D8, 0x0B, 0x32,
    WRITE_C8_D8, 0x0C, 0x34,
    WRITE_C8_D8, 0x0D, 0x35,
    WRITE_C8_D8, 0x0E, 0x01,
    WRITE_C8_D8, 0x0F, 0x01,
    WRITE_C8_D8, 0x20, 0x00,
    WRITE_C8_D8, 0x21, 0x00,
    WRITE_C8_D8, 0x22, 0x00,
    WRITE_C8_D8, 0x23, 0x00,
    WRITE_C8_D8, 0x24, 0x0C,
    WRITE_C8_D8, 0x25, 0x10,
    WRITE_C8_D8, 0x26, 0x20,
    WRITE_C8_D8, 0x27, 0x21,
    WRITE_C8_D8, 0x28, 0x22,
    WRITE_C8_D8, 0x29, 0x23,
    WRITE_C8_D8, 0x2A, 0x33,
    WRITE_C8_D8, 0x2B, 0x32,
    WRITE_C8_D8, 0x2C, 0x34,
    WRITE_C8_D8, 0x2D, 0x35,
    WRITE_C8_D8, 0x2E, 0x01,
    WRITE_C8_D8, 0x2F, 0x01,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x16,
    WRITE_C8_D8, 0x00, 0x00,
    WRITE_C8_D8, 0x01, 0x00,
    WRITE_C8_D8, 0x02, 0x00,
    WRITE_C8_D8, 0x03, 0x00,
    WRITE_C8_D8, 0x04, 0x08,
    WRITE_C8_D8, 0x05, 0x04,
    WRITE_C8_D8, 0x06, 0x19,
    WRITE_C8_D8, 0x07, 0x18,
    WRITE_C8_D8, 0x08, 0x17,
    WRITE_C8_D8, 0x09, 0x16,
    WRITE_C8_D8, 0x0A, 0x33,
    WRITE_C8_D8, 0x0B, 0x32,
    WRITE_C8_D8, 0x0C, 0x34,
    WRITE_C8_D8, 0x0D, 0x35,
    WRITE_C8_D8, 0x0E, 0x01,
    WRITE_C8_D8, 0x0F, 0x01,
    WRITE_C8_D8, 0x20, 0x00,
    WRITE_C8_D8, 0x21, 0x00,
    WRITE_C8_D8, 0x22, 0x00,
    WRITE_C8_D8, 0x23, 0x00,
    WRITE_C8_D8, 0x24, 0x04,
    WRITE_C8_D8, 0x25, 0x08,
    WRITE_C8_D8, 0x26, 0x16,
    WRITE_C8_D8, 0x27, 0x17,
    WRITE_C8_D8, 0x28, 0x18,
    WRITE_C8_D8, 0x29, 0x19,
    WRITE_C8_D8, 0x2A, 0x33,
    WRITE_C8_D8, 0x2B, 0x32,
    WRITE_C8_D8, 0x2C, 0x34,
    WRITE_C8_D8, 0x2D, 0x35,
    WRITE_C8_D8, 0x2E, 0x01,
    WRITE_C8_D8, 0x2F, 0x01,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x12,
    WRITE_C8_D8, 0x00, 0x99,
    WRITE_C8_D8, 0x2A, 0x28,
    WRITE_C8_D8, 0x2B, 0x0f,
    WRITE_C8_D8, 0x2C, 0x16,
    WRITE_C8_D8, 0x2D, 0x28,
    WRITE_C8_D8, 0x2E, 0x0f,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0xA0,
    WRITE_C8_D8, 0x08, 0xdc,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x45,
    WRITE_C8_D8, 0x03, 0x64,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x40,
    WRITE_C8_D8, 0x86, 0x00,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x00,

    WRITE_C8_BYTES, 0x2A, 4, 0x00, 0x00, 0x01, 0x63,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x42,
    WRITE_C8_D8, 0x05, 0x2c,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x11,
    WRITE_C8_D8, 0x50, 0x01,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x12,
    WRITE_C8_D8, 0x0D, 0x66,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x17,
    WRITE_C8_D8, 0x39, 0x3c,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x31,
    WRITE_C8_D8, 0x00, 0x00,
    WRITE_C8_D8, 0x01, 0x00,
    WRITE_C8_D8, 0x02, 0x00,
    WRITE_C8_D8, 0x03, 0x09,
    WRITE_C8_D8, 0x04, 0x00,
    WRITE_C8_D8, 0x05, 0x1c,
    WRITE_C8_D8, 0x06, 0x00,
    WRITE_C8_D8, 0x07, 0x36,
    WRITE_C8_D8, 0x08, 0x00,
    WRITE_C8_D8, 0x09, 0x3d,
    WRITE_C8_D8, 0x0a, 0x00,
    WRITE_C8_D8, 0x0b, 0x54,
    WRITE_C8_D8, 0x0c, 0x00,
    WRITE_C8_D8, 0x0d, 0x62,
    WRITE_C8_D8, 0x0e, 0x00,
    WRITE_C8_D8, 0x0f, 0x72,
    WRITE_C8_D8, 0x10, 0x00,
    WRITE_C8_D8, 0x11, 0x79,
    WRITE_C8_D8, 0x12, 0x00,
    WRITE_C8_D8, 0x13, 0xa6,
    WRITE_C8_D8, 0x14, 0x00,
    WRITE_C8_D8, 0x15, 0xd0,
    WRITE_C8_D8, 0x16, 0x01,
    WRITE_C8_D8, 0x17, 0x0e,
    WRITE_C8_D8, 0x18, 0x01,
    WRITE_C8_D8, 0x19, 0x3d,
    WRITE_C8_D8, 0x1a, 0x01,
    WRITE_C8_D8, 0x1b, 0x7b,
    WRITE_C8_D8, 0x1c, 0x01,
    WRITE_C8_D8, 0x1d, 0xcf,
    WRITE_C8_D8, 0x1e, 0x02,
    WRITE_C8_D8, 0x1f, 0x0E,
    WRITE_C8_D8, 0x20, 0x02,
    WRITE_C8_D8, 0x21, 0x53,
    WRITE_C8_D8, 0x22, 0x02,
    WRITE_C8_D8, 0x23, 0x80,
    WRITE_C8_D8, 0x24, 0x02,
    WRITE_C8_D8, 0x25, 0xC2,
    WRITE_C8_D8, 0x26, 0x02,
    WRITE_C8_D8, 0x27, 0xFA,
    WRITE_C8_D8, 0x28, 0x03,
    WRITE_C8_D8, 0x29, 0x3E,
    WRITE_C8_D8, 0x2a, 0x03,
    WRITE_C8_D8, 0x2b, 0x52,
    WRITE_C8_D8, 0x2c, 0x03,
    WRITE_C8_D8, 0x2d, 0x70,
    WRITE_C8_D8, 0x2e, 0x03,
    WRITE_C8_D8, 0x2f, 0x8E,
    WRITE_C8_D8, 0x30, 0x03,
    WRITE_C8_D8, 0x31, 0xA2,
    WRITE_C8_D8, 0x32, 0x03,
    WRITE_C8_D8, 0x33, 0xBA,
    WRITE_C8_D8, 0x34, 0x03,
    WRITE_C8_D8, 0x35, 0xCF,
    WRITE_C8_D8, 0x36, 0x03,
    WRITE_C8_D8, 0x37, 0xe8,
    WRITE_C8_D8, 0x38, 0x03,
    WRITE_C8_D8, 0x39, 0xf0,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x32,
    WRITE_C8_D8, 0x00, 0x00,
    WRITE_C8_D8, 0x01, 0x00,
    WRITE_C8_D8, 0x02, 0x00,
    WRITE_C8_D8, 0x03, 0x09,
    WRITE_C8_D8, 0x04, 0x00,
    WRITE_C8_D8, 0x05, 0x1c,
    WRITE_C8_D8, 0x06, 0x00,
    WRITE_C8_D8, 0x07, 0x36,
    WRITE_C8_D8, 0x08, 0x00,
    WRITE_C8_D8, 0x09, 0x3d,
    WRITE_C8_D8, 0x0a, 0x00,
    WRITE_C8_D8, 0x0b, 0x54,
    WRITE_C8_D8, 0x0c, 0x00,
    WRITE_C8_D8, 0x0d, 0x62,
    WRITE_C8_D8, 0x0e, 0x00,
    WRITE_C8_D8, 0x0f, 0x72,
    WRITE_C8_D8, 0x10, 0x00,
    WRITE_C8_D8, 0x11, 0x79,
    WRITE_C8_D8, 0x12, 0x00,
    WRITE_C8_D8, 0x13, 0xa6,
    WRITE_C8_D8, 0x14, 0x00,
    WRITE_C8_D8, 0x15, 0xd0,
    WRITE_C8_D8, 0x16, 0x01,
    WRITE_C8_D8, 0x17, 0x0e,
    WRITE_C8_D8, 0x18, 0x01,
    WRITE_C8_D8, 0x19, 0x3d,
    WRITE_C8_D8, 0x1a, 0x01,
    WRITE_C8_D8, 0x1b, 0x7b,
    WRITE_C8_D8, 0x1c, 0x01,
    WRITE_C8_D8, 0x1d, 0xcf,
    WRITE_C8_D8, 0x1e, 0x02,
    WRITE_C8_D8, 0x1f, 0x0E,
    WRITE_C8_D8, 0x20, 0x02,
    WRITE_C8_D8, 0x21, 0x53,
    WRITE_C8_D8, 0x22, 0x02,
    WRITE_C8_D8, 0x23, 0x80,
    WRITE_C8_D8, 0x24, 0x02,
    WRITE_C8_D8, 0x25, 0xC2,
    WRITE_C8_D8, 0x26, 0x02,
    WRITE_C8_D8, 0x27, 0xFA,
    WRITE_C8_D8, 0x28, 0x03,
    WRITE_C8_D8, 0x29, 0x3E,
    WRITE_C8_D8, 0x2a, 0x03,
    WRITE_C8_D8, 0x2b, 0x52,
    WRITE_C8_D8, 0x2c, 0x03,
    WRITE_C8_D8, 0x2d, 0x70,
    WRITE_C8_D8, 0x2e, 0x03,
    WRITE_C8_D8, 0x2f, 0x8E,
    WRITE_C8_D8, 0x30, 0x03,
    WRITE_C8_D8, 0x31, 0xA2,
    WRITE_C8_D8, 0x32, 0x03,
    WRITE_C8_D8, 0x33, 0xBA,
    WRITE_C8_D8, 0x34, 0x03,
    WRITE_C8_D8, 0x35, 0xCF,
    WRITE_C8_D8, 0x36, 0x03,
    WRITE_C8_D8, 0x37, 0xe8,
    WRITE_C8_D8, 0x38, 0x03,
    WRITE_C8_D8, 0x39, 0xf0,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x11,
    WRITE_C8_D8, 0x60, 0x01,
    WRITE_C8_D8, 0x65, 0x03,
    WRITE_C8_D8, 0x66, 0x38,
    WRITE_C8_D8, 0x67, 0x04,
    WRITE_C8_D8, 0x68, 0x34,
    WRITE_C8_D8, 0x69, 0x03,
    WRITE_C8_D8, 0x61, 0x03,
    WRITE_C8_D8, 0x62, 0x38,
    WRITE_C8_D8, 0x63, 0x04,
    WRITE_C8_D8, 0x64, 0x34,
    WRITE_C8_D8, 0x0A, 0x11,
    WRITE_C8_D8, 0x0B, 0x14,
    WRITE_C8_D8, 0x0c, 0x14,
    WRITE_C8_D8, 0x55, 0x06,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x42,
    WRITE_C8_D8, 0x05, 0x3D,
    WRITE_C8_D8, 0x06, 0x03,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x12,
    WRITE_C8_D8, 0x1f, 0xdc,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x17,
    WRITE_C8_D8, 0x11, 0xAA,
    WRITE_C8_D8, 0x16, 0x12,
    WRITE_C8_D8, 0x0B, 0xC3,
    WRITE_C8_D8, 0x10, 0x0E,
    WRITE_C8_D8, 0x14, 0xAA,
    WRITE_C8_D8, 0x18, 0xA0,
    WRITE_C8_D8, 0x1A, 0x80,
    WRITE_C8_D8, 0x1F, 0x80,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x11,
    WRITE_C8_D8, 0x30, 0xEE,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x12,
    WRITE_C8_D8, 0x15, 0x0F,
    WRITE_C8_D8, 0x10, 0x0F,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x40,
    WRITE_C8_D8, 0x83, 0xC4,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x2d,
    WRITE_C8_D8, 0x01, 0x3e,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x12,
    WRITE_C8_D8, 0x2B, 0x1e,
    WRITE_C8_D8, 0x2C, 0x26,
    WRITE_C8_D8, 0x2E, 0x1e,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x18,
    WRITE_C8_D8, 0x01, 0x01,
    WRITE_C8_D8, 0x00, 0x1E,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x43,
    WRITE_C8_D8, 0x03, 0x04,

    // touch For I2C
    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x50,
    WRITE_C8_D8, 0x05, 0x00,
    WRITE_C8_D8, 0x00, 0xA6,
    WRITE_C8_D8, 0x01, 0xA6,
    WRITE_C8_D8, 0x08, 0x55,

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x12,
    WRITE_C8_D8, 0x21, 0xB4, // set vcom

    WRITE_C8_BYTES, 0xFF, 3, 0x20, 0x10, 0x00,
    // ADD FOR QSPI/TP TEST
    WRITE_C8_D8, 0x3A, 0x05,

    WRITE_COMMAND_8, WEA2012_SLPOUT,
    WRITE_COMMAND_8, WEA2012_DISPON,
    END_WRITE};

class Arduino_WEA2012 : public Arduino_TFT
{
public:
  Arduino_WEA2012(Arduino_DataBus *bus, int8_t rst = GFX_NOT_DEFINED);

  bool begin(int32_t speed = GFX_NOT_DEFINED) override;

  void setRotation(uint8_t r) override;

  void writeAddrWindow(int16_t x, int16_t y, uint16_t w, uint16_t h);

  void invertDisplay(bool) override;
  void displayOn() override;
  void displayOff() override;

protected:
  void tftInit() override;

private:
};
