#pragma once

#define USB_KEYBOARD_CODE      ( 0x00000000 )

#define KEY_CODE          ( 0x000000FF )

class UsbKeyboard {
 public:
  UsbKeyboard();
  void setup(void (*callback)(unsigned char, bool));
  void loop();
  void process(unsigned short code, bool pressed);
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
