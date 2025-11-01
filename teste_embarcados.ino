#include <FastLED.h>

// ===== CONFIGURAÇÕES DOS LEDs =====
#define LED_PIN D7        // Pino de dados conectado ao Din da fita
#define NUM_LEDS 8        // Número de LEDs na fita
#define BRIGHTNESS 255    // Brilho máximo (0-255)
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

// ===== CONFIGURAÇÕES DO SENSOR =====
#define LDR_PIN A0        // Pino analógico do sensor de luminosidade

// ===== VARIÁVEIS GLOBAIS =====
int ldrValue = 0;

void setup() {
  Serial.begin(115200);
  delay(100);
  
  Serial.println("\n\n=== Sistema de Controle de Iluminação ===");
  
  // Inicialização dos LEDs com FastLED
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
  
  Serial.println("✓ LEDs inicializados com FastLED");
  Serial.println("=== Sistema pronto! ===\n");
}

void loop() {
  // Leitura do sensor de luminosidade (0-1023)
  ldrValue = analogRead(LDR_PIN);
  
  // Controle dos LEDs baseado na luminosidade
  controleLuminosidade(ldrValue);
  
  // Debug via Serial Monitor
  Serial.print("Luminosidade: ");
  Serial.print(ldrValue);
  Serial.print(" | Modo: ");
  
  if (ldrValue <= 300) {
    Serial.println("Escuridão (Vermelho)");
  } else if (ldrValue <= 600) {
    Serial.println("Crepúsculo (Azul)");
  } else if (ldrValue <= 800) {
    Serial.println("Luz adequada (Branco)");
  } else {
    Serial.println("Luz intensa (Desligado)");
  }
  
  delay(100); // Delay para estabilidade
}

void controleLuminosidade(int valor) {
  // Define cores baseadas no nível de luminosidade
  
  if (valor <= 300) {
    // Escuridão total - LED Vermelho forte
    setColor(255, 0, 0);
  }
  else if (valor <= 600) {
    // Ambiente com pouca luz - LED Azul
    setColor(0, 0, 255);
  }
  else if (valor <= 800) {
    // Luz adequada - LED Branco suave
    setColor(100, 100, 100);
  }
  else {
    // Muita luz - LEDs desligados (economiza energia)
    setColor(0, 0, 0);
  }
}

void setColor(int r, int g, int b) {
  // Define a mesma cor RGB para todos os LEDs da fita usando FastLED
  fill_solid(leds, NUM_LEDS, CRGB(r, g, b));
  FastLED.show(); // Atualiza a fita com as novas cores
}