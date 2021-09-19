#include <Arduino.h>

#include <EEPROM.h>

#include "Leds.h"
#include "Storage.h"

Leds::Leds() {
  
}

void Leds::setup(unsigned long *lastActive) {
  pinMode(k_ledPin, OUTPUT);
  pinMode(k_ledGamePin, OUTPUT);

  m_ledVal = EEPROM.read(STORAGE_OFFSET_LEDS);
  m_ledGameVal = EEPROM.read(STORAGE_OFFSET_LEDS + 1);

  m_lastActive = lastActive;
}

void Leds::loop() {
  if (*m_lastActive+k_activityTimeout > millis()) {
    analogWrite(k_ledPin, m_ledVal);
    analogWrite(k_ledGamePin, m_ledGameVal);
  }
  else {
    analogWrite(k_ledPin, 0);
    analogWrite(k_ledGamePin, 0);
  }
}

void Leds::override(bool doOverride, int val) {
  if (doOverride == m_overrided) {
    return;
  }

  m_overrided = doOverride;

  if (doOverride) {
    m_storedEnableVal = m_enabled;
    m_ledStoredVal = m_ledVal;
    m_ledStoredGameVal = m_ledGameVal;

    enable(true);
    set(&m_ledVal, val, true);
    set(&m_ledGameVal, val, true);
  }
  else {
    enable(m_storedEnableVal);
    set(&m_ledVal, m_ledStoredVal, true);
    set(&m_ledGameVal, m_ledStoredGameVal, true);
  }
}

void Leds::enable(bool doEnable) {
  if (doEnable == m_enabled) {
    return;
  }
  
  if (doEnable) {
    m_enabled = true;
    set(&m_ledVal, m_ledStoredVal, true);
    set(&m_ledGameVal, m_ledStoredGameVal, true);
  }
  else {
    m_ledStoredVal = m_ledVal;
    set(&m_ledVal, 0, true);
    m_ledStoredGameVal = m_ledGameVal;
    set(&m_ledGameVal, 0, true);
    m_enabled = false;
  }
}

void Leds::set(unsigned char *var, int val, bool setEqual) {
  if (m_enabled == false) {
    return;
  }
  
  int newVal = 0;
  
  if (setEqual) {
    newVal = val;
  } else {
    newVal = *var + val;
  }

  if (newVal < 0) {
    newVal = 0;
  }
  else if (newVal > 255) {
    newVal = 255;
  }

  *var = newVal;

  if (var == &m_ledVal) {
    EEPROM.write(STORAGE_OFFSET_LEDS, m_ledVal);
  }
  else if (var == &m_ledGameVal) {
    EEPROM.write(STORAGE_OFFSET_LEDS + 1, m_ledGameVal);
  }
}

void Leds::process(unsigned long code){
  switch (code & (LED_CODE_TYPE | LED_CODE)) {
    case LED_INC:
      set(&m_ledVal, k_ledInc, false);
      break;
    case LED_DEC:
      set(&m_ledVal, -k_ledInc, false);
      break;
    case LED_ON:
      enable(true);
      break;
    case LED_OFF:
      enable(false);
      break;
    case LED_TOGGLE:
      enable(!m_enabled);
      break;
    case LED_INC_GAME:
      set(&m_ledGameVal, k_ledInc, false);
      break;
    case LED_DEC_GAME:
      set(&m_ledGameVal, -k_ledInc, false);
      break;
    case LED_SYNC_GAME:
      set(&m_ledGameVal, m_ledVal, true);
      break;
    case LED_SET:
      set(&m_ledVal, (code & LED_CODE_DATA), true);
      break;
    case LED_SET_GAME:
      set(&m_ledGameVal, (code & LED_CODE_DATA), true);
      break;
  }
}
