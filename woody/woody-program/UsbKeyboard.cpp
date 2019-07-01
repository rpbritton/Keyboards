#include <Arduino.h>

#include "UsbKeyboard.h"

extern volatile uint8_t keyboard_leds;

UsbKeyboard::UsbKeyboard() {
}

void UsbKeyboard::setup(Leds *leds) {
  m_leds = leds;
}

void UsbKeyboard::loop() {
  if (m_capsLock == !(keyboard_leds & 0x02)) {
    m_capsLock = !m_capsLock;
    m_leds->override(m_capsLock);
  }

  if (m_changed) {
    Keyboard.send_now();
    m_changed = false;
  }
}

void UsbKeyboard::process(unsigned short key, bool released) {
  unsigned short keyCode = key & KEY_CODE;
  
  switch (key & KEY_TYPE) {
    case KEY_TYPE_NORMAL:
      if (released) {
        for (int x = 0; x < 6; ++x) {
          if (m_keys[x] == keyCode) {
            for (; x < 5; ++x) {
              if (m_keys[x] != 0) {
                setKey(x, m_keys[x + 1]);
              }
            }
            setKey(x + 1, 0);
            break;
          }
          else if (m_keys[x] == 0) {
            return;
          }
        }
      }
      else {
        for (int x = 0; x < 6; ++x) {
          if (m_keys[x] == keyCode) {
            break;
          }
          else if (m_keys[x] == 0) {
            setKey(x, keyCode);
            break;
          }
        }
      }
      break;
    case KEY_TYPE_MODIFIER:
      if (released) {
        if (m_modifiers & keyCode) {
          m_modifiers &= ~keyCode;
        }
        else {
          return;
        }
      }
      else {
        if (m_modifiers & keyCode) {
          return;
        }
        else {
          m_modifiers |= keyCode;
        }
      }
      Keyboard.set_modifier(m_modifiers);
      break;
    case KEY_TYPE_SYSTEM:
      break;
    case KEY_TYPE_MEDIA:
      if (released) {
      }
      else {
        Keyboard.set_media(key);
      }
      break;
    default:
      return;
  }
  
  m_changed = true;
}

void UsbKeyboard::setKey(int index, unsigned char keyCode) {
  switch (index) {
    case 0:
      m_keys[0] = keyCode;
      Keyboard.set_key1(keyCode);
      break;
    case 1:
      m_keys[1] = keyCode;
      Keyboard.set_key2(keyCode);
      break;
    case 2:
      m_keys[2] = keyCode;
      Keyboard.set_key3(keyCode);
      break;
    case 3:
      m_keys[3] = keyCode;
      Keyboard.set_key4(keyCode);
      break;
    case 4:
      m_keys[4] = keyCode;
      Keyboard.set_key5(keyCode);
      break;
    case 5:
      m_keys[5] = keyCode;
      Keyboard.set_key6(keyCode);
      break;
  }
}
