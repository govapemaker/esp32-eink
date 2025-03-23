#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
// Thêm font lớn hơn
#include <Fonts/FreeMonoBold18pt7b.h>
#include <SPI.h>


// Giữ nguyên cài đặt ban đầu
GxEPD2_3C<GxEPD2_420_Z98c, GxEPD2_420_Z98c::HEIGHT> display(
    GxEPD2_420_Z98c(/*CS=*/ 15, /*DC=*/ 27, /*RST=*/ 26, /*BUSY=*/ 25)
);
void setup() {
  Serial.begin(115200);
  Serial.println("300x400px E-Paper Display Demo");
    SPI.begin(13, -1, 14, 15); // SCLK=13, MISO=-1 (không dùng), MOSI=14, CS=15

  // Khởi tạo màn hình
  display.init();
  
  // Xóa màn hình (nền trắng)
  display.clearScreen();
  
  // Bắt đầu vẽ, toàn bộ màn hình
  display.setFullWindow();
  display.firstPage();
  
  do {
    display.fillScreen(GxEPD_WHITE); // đặt nền màu trắng
    
    // Đặt màu chữ thứ nhất (đen) với font lớn hơn
    display.setTextColor(GxEPD_BLACK);
    display.setFont(&FreeMonoBold18pt7b);  // Sử dụng font lớn hơn
    
    // Căn giữa "Hello World!" theo chiều ngang
   // String text1 = "Hello World!";
   String text1 = "E-INK 4.2INCH";
    int16_t x1, y1;
    uint16_t w1, h1;
    display.getTextBounds(text1, 0, 0, &x1, &y1, &w1, &h1);
    display.setCursor((300 - w1) / 2, 120);
    display.println(text1);
    
    // Căn giữa "Xin chao!" theo chiều ngang
    display.setTextColor(GxEPD_RED);
    String text2 = "Quy Nguyen";
    int16_t x2, y2;
    uint16_t w2, h2;
   display.getTextBounds(text2, 0, 0, &x2, &y2, &w2, &h2);
   display.setCursor((300 - w2) / 2, 220);
   display.println(text2);
    
    // Vẽ vòng tròn màu đỏ ở giữa màn hình (theo chiều ngang) với kích thước nhỏ hơn
    //display.fillCircle(300 / 2, 300, 10, GxEPD_RED);  // Giảm bán kính từ 30 xuống 15
    
  } while (display.nextPage());
  
  // Khi đã hoàn tất, đặt về chế độ sleep
  display.hibernate();
}

void loop() {
  // Không cần làm gì trong loop
}
