#include <Adafruit_NeoPixel.h>

#define PIN A3
#define NUM_LEDS 16
// We use these macros because binary constants arent always supported. ugh.

#define HEX__(n) 0x##n##UL
#define B8__(x) ((x&0x0000000FLU)?1:0) +((x&0x000000F0LU)?2:0) +((x&0x00000F00LU)?4:0) +((x&0x0000F000LU)?8:0) +((x&0x000F0000LU)?16:0) +((x&0x00F00000LU)?32:0) +((x&0x0F000000LU)?64:0) +((x&0xF0000000LU)?128:0)
#define B8(d) ((unsigned char)B8__(HEX__(d)))

const static int image[] = { B8(00000000), 
B8(00000000), 
B8(00000000), 
B8(00000000), 
B8(00000000), 
B8(00000000), 
B8(00000000), 
B8(00000000), 
B8(01000100), 
B8(01010100), 
B8(01111100), 
B8(00000000), 
B8(01000100), 
B8(01000100), 
B8(00111000), 
B8(00000000), 
B8(01110000), 
B8(00011000), 
B8(00010100), 
B8(00010100), 
B8(00011000), 
B8(01110000), 
B8(00000000), 
B8(01000100), 
B8(01010100), 
B8(01111100), 
B8(00000000), 
B8(00011100), 
B8(00010100), 
B8(01111100), 
B8(00000000), 
B8(00000000), 
B8(00000000), 
B8(00000000), 
B8(00000000), 
B8(00000000)};

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
int num_columns = sizeof(image);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  for (int c = 0; c < num_columns; c++) {
    showColumn(c);
    delay(5);
  }
  for (int c = num_columns - 1; c > -1; c--) {
    showColumn(c);
    delay(5);
  }
}

void showColumn(int c) {
  for (int i=0; i < 8; i++) {
    if (image[c] & (0x1 << i)) {
      strip.setPixelColor(2*(7-i), strip.Color(128,0,128));
      strip.setPixelColor(2*(7-i)+1, strip.Color(128,0,128));
    }
    else {
      strip.setPixelColor(2*(7-i), strip.Color(0,0,0));
      strip.setPixelColor(2*(7-i)+1, strip.Color(0,0,0));
    }
  }
  strip.show();
}
