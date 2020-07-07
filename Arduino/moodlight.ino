#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define BUTTON_PIN   2
#define OFF_BUTTON_PIN 3
#define PIXEL_PIN    6
#define PIXEL_COUNT 1

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(OFF_BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show();
  attachInterrupt(digitalPinToInterrupt(OFF_BUTTON_PIN), btnOffInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), btnDownInterrupt, FALLING);
}

void loop() {
  Serial.println(digitalRead(OFF_BUTTON_PIN));
  delay(1000);
}

void btnOffInterrupt(){
  Serial.print("off\n");
  colorWipe((0, 0, 0), 50);
}

void btnDownInterrupt(){
  delay(20);
  Serial.print("inter\n");
  rainbow(10);  
}

void colorWipe(uint32_t color, int wait) {
  while(1){
    for(int i=0; i<strip.numPixels(); i++) { 
      strip.setPixelColor(i, color);         
      strip.show();                          
      delay(wait);                          
    }
  }
}

void rainbow(int wait) {
  while(1){
    for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256) {
      for(int i=0; i<strip.numPixels(); i++) {
        int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
        strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
        delay(wait);
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

