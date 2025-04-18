

#include <GxEPD.h>
#include <GxGDEH029A1/GxGDEH029A1.h> // Thư viện cho màn hình e-paper 2.9 inch
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <SPI.h>

// Cấu hình SPI và e-paper
#if defined(ESP32)
GxIO_Class io(SPI, /*CS=*/ 15, /*DC=*/ 27, /*RST=*/ 26); 
GxEPD_Class display(io, /*RST=*/ 26, /*BUSY=*/ 25);
#endif

// 'EINK-QUYNGUYEN', 128x296px
//convert ảnh ra bitmap => https://javl.github.io/image2cpp/
const unsigned char epd_bitmap_EINK [] PROGMEM = {
 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf8, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xe0, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x00, 0x00, 0x1f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x03, 0xf0, 0x1f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x0f, 0xfc, 0x0f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x1f, 0xfe, 0x0f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x87, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x1f, 0xfe, 0x0f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x0f, 0xfc, 0x0f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x07, 0xf8, 0x1f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x03, 0xf0, 0x1f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x01, 0xe0, 0x3f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x80, 0xc0, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xe0, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf0, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xe0, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x01, 0xe0, 0x3f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x03, 0xf0, 0x3f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x07, 0xf8, 0x1f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x0f, 0xfc, 0x0f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x1f, 0xfe, 0x0f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x1f, 0xfe, 0x07, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf1, 0xf0, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x7f, 0x3f, 0x07, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x78, 0x07, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x78, 0x07, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf8, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x78, 0x07, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf8, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf8, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfd, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x7f, 0x3f, 0x83, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x1f, 0xfe, 0x07, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x0f, 0xfc, 0x0f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x7f, 0x3f, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x07, 0xf8, 0x0f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xfe, 0x1f, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x00, 0xc0, 0x1f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xfc, 0x0f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf1, 0xf8, 0xc7, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf1, 0xf8, 0xe3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf1, 0xf9, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf0, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xf1, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xf1, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x03, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0x07, 0xf7, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x00, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x00, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x7e, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0x87, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xc7, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x7f, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xf0, 0x3f, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xe0, 0x07, 0xc3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xc3, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xc7, 0x80, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xc7, 0xe0, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x00, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x70, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0x83, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xfb, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x00, 0x21, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf1, 0xf0, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf8, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf8, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf8, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfb, 0xfd, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x20, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf0, 0x7e, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf8, 0x3e, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfe, 0x0e, 0x3f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x03, 0x1f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xc3, 0x9f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xe3, 0xdf, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf0, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf0, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf0, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf0, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x00, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x00, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x7f, 0xfb, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x7e, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0x87, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xc7, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xf7, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xf1, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xf1, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x31, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf0, 0x00, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x01, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf0, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x01, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x01, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfb, 0xc7, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x0c, 0x3f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0x1e, 0x1f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x3f, 0x0f, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x7f, 0x87, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xff, 0xe3, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x78, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xfb, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xc3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x07, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x00, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0xff, 0xef, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x1f, 0xc7, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x0f, 0xe3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xc7, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xe3, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xf3, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xfb, 0xfe, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xf1, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xfc, 0x23, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xfe, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0x07, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf8, 0x07, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf0, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x7f, 0xfb, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf1, 0xf1, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf1, 0xe3, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xe3, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xe7, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xe0, 0x02, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x63, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xf1, 0x82, 0x67, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0x33, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xf1, 0xe2, 0x23, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x01, 0xe3, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xf1, 0xe3, 0x33, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xf1, 0xe3, 0x93, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0xf1, 0xe3, 0x13, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfd, 0xe2, 0x27, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xe2, 0x67, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xf2, 0xf3, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x7f, 0xff, 0xfb, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x00, 0x7f, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x30, 0x1f, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x00, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xf8, 0x0f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf1, 0xfc, 0xc7, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xfc, 0xe3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xfc, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf1, 0xfc, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x00, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf8, 0x01, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xff, 0x7f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x7e, 0x3f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0x3c, 0x7f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x10, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x81, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0x11, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x78, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xfc, 0x7f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xfe, 0x3f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xc7, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xe3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x43, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x70, 0x01, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0xff, 0xef, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x1f, 0xc7, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x0f, 0xe3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xc7, 0xf3, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xe3, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xf3, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xf1, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xfc, 0x23, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xfe, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xff, 0x07, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x07, 0x0f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0x02, 0x07, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xf0, 0x63, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xf8, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf8, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf3, 0xf8, 0xf9, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xf8, 0xf1, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf9, 0xf0, 0x71, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xf8, 0xe2, 0x03, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfc, 0x03, 0x07, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 4752)
const int epd_bitmap_allArray_LEN = 1;
const unsigned char* epd_bitmap_allArray[1] = {
  epd_bitmap_EINK
};


// Hàm hiển thị bitmap
void drawBitmapExample() {
  display.fillScreen(GxEPD_WHITE); // Xóa màn hình (tô màu trắng)
  
  // Vẽ bitmap, lưu ý kích thước 128x296
  display.drawBitmap(0, 0, epd_bitmap_EINK, 128, 296, GxEPD_BLACK);
  
  display.update(); // Cập nhật nội dung hiển thị
}

// Hàm setup
void setup() {
  Serial.begin(115200);
  Serial.println("Khởi tạo...");
   Serial.begin(115200);
    SPI.begin(13, -1, 14, 15); // SCLK=13, MISO=-1 (không dùng), MOSI=14, CS=15
  display.init(115200); // Khởi tạo màn hình với tốc độ SPI
  drawBitmapExample();  // Gọi hàm vẽ bitmap
}

// Vòng lặp chính
void loop() {
  // Không cần làm gì trong vòng lặp chính
}
