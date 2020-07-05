#include <Arduino.h>
#include <HID-Project.h>

#include "UsbKeyboard.h"

UsbKeyboard::UsbKeyboard() {
}

void UsbKeyboard::setup(void (*callback)(unsigned char, bool)) {
  m_callback = callback;

  SingleNKROKeyboard.begin();
  Consumer.begin();
}

void UsbKeyboard::loop() {
  unsigned char ledsMask = SingleNKROKeyboard.getLeds();
  if (m_ledsMask != ledsMask) {
    for (int i = 0; i < sizeof(k_ledCodes)/sizeof(k_ledCodes[0]); i += 2) {
      if ((ledsMask & k_ledCodes[i]) != (m_ledsMask & k_ledCodes[i])) {
        m_callback(k_ledCodes[i+1], ((ledsMask & k_ledCodes[i]) > 0));
      }
    }
    m_ledsMask = ledsMask;
  }

  if (m_changed) {
    SingleNKROKeyboard.send();
    m_changed = false;
  }
}

void UsbKeyboard::process(unsigned short key, bool pressed) {
  if ((key == KEY_LEFT_GUI || key == KEY_RIGHT_GUI) && !m_winKeyEnabled) {
    return;
  }

  if ((key >= 0xB0 && key <= 0xB7) || key == 0xE2 || key == 0xE9 || key == 0xEA) { // Media keys
    if (pressed) {
      Consumer.press(key);
    } else {
      Consumer.release(key);
    }
  } else { // All other keys
    KeyboardKeycode keyCode = key & KEY_CODE;
    if (pressed) {
      SingleNKROKeyboard.add(keyCode);
    } else {
      SingleNKROKeyboard.remove(keyCode);
    }
  }
  
  m_changed = true;
}

void UsbKeyboard::toggleWinKey() {
  if (m_winKeyEnabled) {
    process(KEY_LEFT_GUI, false);
    process(KEY_RIGHT_GUI, false);
  }
  m_winKeyEnabled = !m_winKeyEnabled;
}
