#include <Arduino.h>

#include "Leds.h"

Leds::Leds() {}

void Leds::setup() {
  for (int i = 0; i < sizeof(k_pins)/sizeof(k_pins[0]); i++) {
    pinMode(k_pins[i], OUTPUT);
    set(i);
  }
}

void Leds::loop() {}

void Leds::set(int led) {
  if (m_enabled[led] == false) {
    analogWrite(k_pins[led], 255);
  } else {
    analogWrite(k_pins[led], 255 - m_values[led]);
  }
}

void Leds::process(unsigned long code, bool status){
  switch (code & (LED_CODE_TYPE | LED_CODE)) {
    case LED_ON:
      m_enabled[code & LED_CODE_DATA] = true;
      break;
    case LED_OFF:
      m_enabled[code & LED_CODE_DATA] = false;
      break;
    case LED_TOGGLE:
      m_enabled[code & LED_CODE_DATA] = !m_enabled[code & LED_CODE_DATA];
      break;
    case LED_SET:
      m_enabled[code & LED_CODE_DATA] = status;
      break;
    case LED_INVERT:
      m_enabled[code & LED_CODE_DATA] = !status;
      break;
  }
  set(code & LED_CODE_DATA);
}
