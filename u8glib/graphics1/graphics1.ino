#include "U8glib.h"

// setup u8g object
U8GLIB_ST7920_128X64 u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, U8G_PIN_NONE, U8G_PIN_NONE, 17, 16);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16

const uint8_t rook_bitmap[] U8G_PROGMEM = {
  0x00,         // 00000000 
  0x55,         // 01010101
  0x7f,          // 01111111
  0x3e,         // 00111110
  0x3e,         // 00111110 
  0x3e,         // 00111110
  0x3e,         // 00111110 
  0x7f           // 01111111
};

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.drawBitmapP( 0, 0, 1, 8, rook_bitmap);
}

void setup(void) {
}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(1000);
}