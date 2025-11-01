#include <FastLED.h>

// CONFIGURACOES - Ajuste aqui conforme sua fita
#define LED_PIN     D7       // Pino D2 do NodeMCU conectado ao DIN
#define NUM_LEDS    8       // Numero de LEDs na sua fita
#define BRIGHTNESS  50       // Brilho de 0 a 255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Pisca VERMELHO
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
  delay(500);
  
  // Apaga
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(500);
  
  // Pisca VERDE
  fill_solid(leds, NUM_LEDS, CRGB::Green);
  FastLED.show();
  delay(500);
  
  // Apaga
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(500);
  
  // Pisca AZUL
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
  delay(500);
  
  // Apaga
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(500);
  
  // Pisca BRANCO
  fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
  delay(500);
  
  // Apaga
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(500);
}