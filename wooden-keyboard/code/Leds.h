#pragma once

#define LED_CODE      ( 0x20000000 )
#define LED_CODE_TYPE ( 0x00FF0000 )
#define LED_CODE_DATA ( 0x0000FFFF )

enum LedsCodes {
  LED_INC =       ( 0x00000000 | LED_CODE ),
  LED_DEC =       ( 0x00010000 | LED_CODE ),
  LED_ON =        ( 0x00020000 | LED_CODE ),
  LED_OFF =       ( 0x00030000 | LED_CODE ),
  LED_TOGGLE =    ( 0x00040000 | LED_CODE ),
  LED_INC_GAME =  ( 0x00050000 | LED_CODE ),
  LED_DEC_GAME =  ( 0x00060000 | LED_CODE ),
  LED_SYNC_GAME = ( 0x00070000 | LED_CODE ),
  LED_SET =       ( 0x00080000 | LED_CODE ),
  LED_SET_GAME =  ( 0x00090000 | LED_CODE ),
};

class Leds {
 public:
  Leds();
  void setup(unsigned long *lastActive);
  void loop();
  void process(unsigned long code);
  void override(bool doOverride, int val = k_defaultOverride);

 private:
  void enable(bool doEnable);
  void set(unsigned char *var, int val, bool setEqual);
 
  static const unsigned char k_ledPin = 10;
  static const unsigned char k_ledGamePin = 9;

  static const unsigned char k_ledInc = 10;
  static const unsigned char k_defaultOverride = 255;

  static const unsigned long k_activityTimeout = 900000;

  unsigned char m_ledVal = 0;
  unsigned char m_ledGameVal = 0;

  bool m_enabled = true;
  bool m_overrided = false;
  
  unsigned char m_ledStoredVal = 0;
  unsigned char m_ledStoredGameVal = 0;
  bool m_storedEnableVal = true;

  unsigned long *m_lastActive;
};
