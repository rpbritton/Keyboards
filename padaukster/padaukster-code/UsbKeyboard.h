#pragma once

#include "Leds.h"

#define USB_KEYBOARD_CODE      ( 0x00000000 )

#define KEY_TYPE          ( 0x0000FF00 )
#define KEY_TYPE_NORMAL   ( 0x0000F000 )
#define KEY_TYPE_MODIFIER ( 0x0000E000 )
#define KEY_TYPE_SYSTEM   ( 0x0000E200 )
#define KEY_TYPE_MEDIA    ( 0x0000E400 )
#define KEY_CODE          ( 0x000000FF )

class UsbKeyboard {
 public:
  UsbKeyboard();
  void setup(Leds *leds);
  void loop();
  void process(unsigned short code, bool pressed);
  void toggleWinKey();

 private:
  void setKey(int index, unsigned char key);
  
  unsigned char m_keys[6] = {0};
  unsigned short m_modifiers = KEY_TYPE_MODIFIER;
  bool m_changed = false;
  
  Leds *m_leds;
  bool m_capsLock = false;

  bool m_winKeyEnabled = false;
};
