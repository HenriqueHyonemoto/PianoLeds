// Imports da Fita Led
#include <FastLED.h>
#define LED_PIN 7  //Coloque o mesmo numero que você conectou a fita no arduino
#define NUM_LEDS 176
CRGB leds[NUM_LEDS];

//Imports do Piano
#include <MIDI.h>
MIDI_CREATE_INSTANCE(decltype(Serial), Serial, MIDI);

//Executa 1x
void setup() {
  // Inicializando o input de MIDI
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(9600);
  Serial.setTimeout(10);
  // Inicializando a Fita LED
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
  ///para gerar numeros aleatorios
}

//Escolhendo a cor dos leds
int r, g, b;

int brilho = 65; //Escolha aqui o valor do brilho 0 a 255

void corAleatoria() {
  r = random(0, 256);  // Gera um valor aleatório para R (0 a 255)
  g = random(0, 256);  // Gera um valor aleatório para G (0 a 255)
  b = random(0, 256);  // Gera um valor aleatório para B (0 a 255)
}

//Executa Sempre
void loop() {

  FastLED.setBrightness(brilho);
  if (MIDI.read()) {
    uint8_t note = MIDI.getData1();
    uint8_t velocity = MIDI.getData2();
    if (MIDI.getType() == midi::NoteOn || MIDI.getType() == midi::NoteOff) {
      //escolhe a cor dos leds
      corAleatoria();

      //caso a fita comece pelo lado inverso
      uint8_t noteLed = -2 * note + 217;
      if (velocity > 0) {
        if (note == 108) {
          leds[0] = CRGB(r, g, b);
          leds[1] = CRGB(r, g, b);
          leds[2] = CRGB(r, g, b);
        } else if (note == 21) {
          leds[173] = CRGB(r, g, b);
          leds[174] = CRGB(r, g, b);
          leds[175] = CRGB(r, g, b);
        } else if (note < 73 && note > 35) {
          leds[noteLed - 1] = CRGB(r, g, b);
          leds[noteLed] = CRGB(r, g, b);
        } else if (note < 36) {
          leds[noteLed - 2] = CRGB(r, g, b);
          leds[noteLed - 1] = CRGB(r, g, b);
        } else {
          leds[noteLed] = CRGB(r, g, b);
          leds[noteLed + 1] = CRGB(r, g, b);
        }
      }
      if (velocity == 0) {
        if (note == 108) {
          leds[0] = CRGB::Black;
          leds[1] = CRGB::Black;
          leds[2] = CRGB::Black;
        } else if (note == 21) {
          leds[173] = CRGB::Black;
          leds[174] = CRGB::Black;
          leds[175] = CRGB::Black;
        } else if (note < 73 && note > 35) {
          leds[noteLed - 1] = CRGB::Black;
          leds[noteLed] = CRGB::Black;
        } else if (note < 36) {
          leds[noteLed - 2] = CRGB::Black;
          leds[noteLed - 1] = CRGB::Black;
        } else {
          leds[noteLed] = CRGB::Black;
          leds[noteLed + 1] = CRGB::Black;
        }
      }
    }
    FastLED.show();
  }
}