#include <Adafruit_NeoPixel.h>

#define PIN A3
#define NUM_LEDS 8
// We use these macros because binary constants arent always supported. ugh.

#define HEX__(n) 0x##n##UL
#define B8__(x) ((x&0x0000000FLU)?1:0) +((x&0x000000F0LU)?2:0) +((x&0x00000F00LU)?4:0) +((x&0x0000F000LU)?8:0) +((x&0x000F0000LU)?16:0) +((x&0x00F00000LU)?32:0) +((x&0x0F000000LU)?64:0) +((x&0xF0000000LU)?128:0)
#define B8(d) ((unsigned char)B8__(HEX__(d)))

const static int image[] = { B8(10001111), B8(01001001), B8(00101001), B8(00011001), B8(00001001), B8(11111111), B8(00000000), B8(10000001), B8(10001001), B8(10001001), B8(10001001), B8(11111111), B8(00000000), B8(00000001), B8(00000001), B8(11111111), B8(00000001), B8(00000001), B8(00000000), B8(11111001), B8(10001001), B8(10001001), B8(10001001), B8(10001111), B8(00000000), B8(11111111), B8(10000001), B8(10000001), B8(10000001), B8(11111111), B8(00000000), B8(00000001), B8(00000001), B8(00001001), B8(00001001), B8(11111111)};
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
int num_columns = sizeof(image);
int column = 0;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  for (int i=0; i < 8; i++) {
    if (image[column] & (0x1 << i)) {
      strip.setPixelColor(i, strip.Color(128,0,0));
    }
    else {
      strip.setPixelColor(i, strip.Color(0,0,0));
    }
  }
  strip.show();
  column++;
  column %= num_columns;
  if (column == 0) {
    delay(num_columns*5);
  } else {
    delay(5);
  }
}
