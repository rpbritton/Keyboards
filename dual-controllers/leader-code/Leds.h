#pragma once

#define LED_CODE       ( 0x20000000 )
#define LED_CODE_TYPE  ( 0x00FF0000 )
#define LED_CODE_DATA  ( 0x0000FFFF )

enum LedsCodes {
  LED_ON =        ( 0x00020000 | LED_CODE ),
  LED_OFF =       ( 0x00030000 | LED_CODE ),
  LED_TOGGLE =    ( 0x00040000 | LED_CODE ),
  LED_SET =       ( 0x00050000 | LED_CODE ),
  LED_INVERT =    ( 0x00060000 | LED_CODE ),
};

class Leds {
 public:
  Leds();
  void setup();
  void loop();
  void process(unsigned long code, bool status);

 private:
  void set(int led);
  
  static const unsigned char k_numLeds = 2;
  
  const unsigned char k_pins[k_numLeds] = {5, 6};

  unsigned char m_values[k_numLeds] = {255, 255};
  bool m_enabled[k_numLeds] = {false, false};
};
