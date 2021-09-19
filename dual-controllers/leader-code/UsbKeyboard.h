#pragma once

#define USB_KEYBOARD_CODE      ( 0x00000000 )
#define USB_KEYBOARD_CODE_TYPE ( 0x00FF0000 )
#define USB_KEYBOARD_CODE_DATA ( 0x0000FFFF )

enum USBCodes {
  DEFAULT_KEY =    ( 0x00000000 | USB_KEYBOARD_CODE ),
  MEDIA_KEY =      ( 0x00010000 | USB_KEYBOARD_CODE ),
};

class UsbKeyboard {
 public:
  UsbKeyboard();
  void setup(void (*callback)(unsigned char, bool));
  void loop();
  void process(unsigned long code, bool pressed);
  void toggleWinKey();

 private:
  void (*m_callback)(unsigned char, bool);
  
  bool m_changed = false;

  static const unsigned char k_numLeds = 2;
  const unsigned char k_ledCodes[k_numLeds * 2] = {
    LED_CAPS_LOCK, 87, LED_SCROLL_LOCK, 88,
  };
  unsigned char m_ledsMask = 0xFF;
  
  bool m_winKeyEnabled = true;
};
