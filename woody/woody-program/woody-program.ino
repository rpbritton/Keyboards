#include <Arduino.h>

#include "Matrix.h"
#include "Knobs.h"
#include "Leds.h"
#include "UsbKeyboard.h"

#include "Layout.h"

Matrix matrix;
Knobs knobs;
Leds leds;
UsbKeyboard usbKeyboard;

unsigned int currentLayer = 0;

void setup() {
  Serial.begin(1);
  matrix.setup(layoutCallback);
  knobs.setup(layoutCallback);
  leds.setup();
  usbKeyboard.setup(&leds);
}

void layoutCallback(unsigned char index, bool state, int layer) {
  unsigned long result = Layout[layer][index];

  switch (result & EVENT_TYPE) {
    case BOTH_EVENTS:
      break;
    case ON_EVENTS:
      if (!state) {
        return;
      }
      break;
    case BOTH_ON_EVENTS:
      if (state) {
        layoutCallback(index, false, layer);
        if ((result & CODE_TYPE) == USB_KEYBOARD_CODE) {
          Keyboard.send_now();
        }
      }
      break;
    case OFF_EVENTS:
      if (state) {
        return;
      }
      break;
    case BOTH_OFF_EVENTS:
      if (!state) {
        layoutCallback(index, true, layer);
        if ((result & CODE_TYPE) == USB_KEYBOARD_CODE) {
          Keyboard.send_now();
        }
      }
      break;
    case NO_EVENTS:
      return;
  }
  
  switch (result & CODE_TYPE) {
    case USB_KEYBOARD_CODE:
      usbKeyboard.process(result, state);
      break;
    case LAYOUT_CODE:
      switch (result & (LAYOUT_CODE_TYPE | LAYOUT_CODE)) {
        case EMPTY_LAYER:
          for (int layer = currentLayer - 1; layer >= 0; --layer) {
            if ((Layout[layer][index] & EVENT_TYPE) != LAYOUT_CODE
                || (Layout[layer][index] & LAYOUT_CODE_TYPE) != EMPTY_LAYER) {
              layoutCallback(index, state, layer);
              return;
            }
          }
          return;
        case LAYER:
          int newLayer = result & LAYOUT_CODE_DATA;
          if (newLayer < 0 || newLayer >= NUM_LAYERS) {
            return;
          }
          currentLayer = newLayer;
      }
      break;
    case LED_CODE:
      leds.process(result);
      break;
  }
}
void layoutCallback(unsigned char index, bool state) { layoutCallback(index, state, currentLayer); }
void layoutCallback(unsigned char index) { layoutCallback(index, true, currentLayer); }

void loop() {
  matrix.loop();
  knobs.loop();
  leds.loop();
  usbKeyboard.loop();
}
