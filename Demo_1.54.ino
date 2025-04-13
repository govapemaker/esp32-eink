#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <SPI.h>

GxEPD2_BW<GxEPD2_150_BN, GxEPD2_150_BN::HEIGHT> display(
  GxEPD2_150_BN(/*CS=*/ 15, /*DC=*/ 27, /*RST=*/ 26, /*BUSY=*/ 25)
);

void setup() {
  Serial.begin(115200);
  Serial.println("200x200px E-Paper Display Demo");
  SPI.begin(13, -1, 14, 15);

  display.init();
  display.clearScreen();
  display.setFullWindow();
  display.firstPage();

  do {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(&FreeMonoBold18pt7b);
    
    String text1 = "EInk 1.54";
    int16_t x1, y1; uint16_t w1, h1;
    display.getTextBounds(text1, 0, 0, &x1, &y1, &w1, &h1);
    display.setCursor((200 - w1) / 2, 80);
    display.println(text1);

    String text2 = "TEST";
    int16_t x2, y2; uint16_t w2, h2;
    display.getTextBounds(text2, 0, 0, &x2, &y2, &w2, &h2);
    display.setCursor((200 - w2) / 2, 150);
    display.println(text2);

  } while (display.nextPage());

  display.hibernate();
}

void loop() {}
