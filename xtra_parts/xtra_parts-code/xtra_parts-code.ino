#include <Arduino.h>

#include "Matrix.h"
#include "UsbKeyboard.h"

#include "Layout.h"

Matrix matrix;
UsbKeyboard usbKeyboard;

unsigned int currentLayer = 0;

void setup() {
  matrix.setup(layoutCallback);
  usbKeyboard.setup();
}

int lastIndex = 0;

void processCode(unsigned long code, bool on) {
  switch (code & CODE_TYPE) {
    case USB_KEYBOARD_CODE:
      usbKeyboard.process(code, on);
      break;
    case LAYOUT_CODE:
      switch (code & (LAYOUT_CODE_TYPE | LAYOUT_CODE)) {
        case EMPTY_LAYER: {
          for (int layer = currentLayer - 1; layer >= 0; --layer) {
            if ((Layout[layer][lastIndex] & EVENT_TYPE) != LAYOUT_CODE
                || (Layout[layer][lastIndex] & LAYOUT_CODE_TYPE) != EMPTY_LAYER) {
              layoutCallback(lastIndex, on, layer);
              break;
            }
          }
		    } break;
        case LAYER: {
          int newLayer = code & LAYOUT_CODE_DATA;
          if (newLayer < 0 || newLayer >= NUM_LAYERS) {
            break;
          }
          currentLayer = newLayer;
        } break;
        case TOGGLE_WIN_KEY: {
          usbKeyboard.toggleWinKey();
        } break;
      }
      break;
  }
}

void layoutCallback(unsigned char index, bool on, int layer) {
  lastIndex = index;
  unsigned long code = Layout[layer][index];

  switch (code & EVENT_TYPE) {
    case BOTH_EVENTS:
      processCode(code, on);
      break;
    case ON_EVENTS:
      if (on) {
        processCode(code, true);
      }
      break;
    case BOTH_ON_EVENTS:
      if (on) {
        processCode(code, true);
        if ((code & CODE_TYPE) == USB_KEYBOARD_CODE) {
          Keyboard.send_now();
        }
        processCode(code, false);
      }
      break;
    case OFF_EVENTS:
      if (!on) {
        processCode(code, false);
      }
      break;
    case BOTH_OFF_EVENTS:
      if (!on) {
        processCode(code, true);
        if ((code & CODE_TYPE) == USB_KEYBOARD_CODE) {
          Keyboard.send_now();
        }
        processCode(code, false);
      }
      break;
    case NO_EVENTS:
      break;
  }
}
void layoutCallback(unsigned char index, bool state) { layoutCallback(index, state, currentLayer); }
void layoutCallback(unsigned char index) { layoutCallback(index, true, currentLayer); }

void loop() {
  matrix.loop();
  usbKeyboard.loop();
}
