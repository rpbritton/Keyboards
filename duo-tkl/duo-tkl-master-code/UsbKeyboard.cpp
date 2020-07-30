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

void UsbKeyboard::process(unsigned long code, bool pressed) {
  switch (code & (USB_KEYBOARD_CODE_TYPE | USB_KEYBOARD_CODE)) {
    case DEFAULT_KEY: {
      KeyboardKeycode key = code & USB_KEYBOARD_CODE_DATA;

      if ((key == KEY_LEFT_GUI) && !m_winKeyEnabled) {
        return;
      }
      
      if (pressed) {
        SingleNKROKeyboard.add(key);
      } else {
        SingleNKROKeyboard.remove(key);
      }
    } break;
    case MEDIA_KEY: {
      ConsumerKeycode key = code & USB_KEYBOARD_CODE_DATA;
      if (pressed) {
        Consumer.press(key);
      } else {
        Consumer.release(key);
      }
    } break;
  }
  
  m_changed = true;
}

void UsbKeyboard::toggleWinKey() {
  if (m_winKeyEnabled) {
    process(KEY_LEFT_GUI, false);
  }
  m_winKeyEnabled = !m_winKeyEnabled;
}
