#include <Arduino.h>

#include "Matrix.h"

void Matrix::setup(void (*callback)(unsigned char, bool)) {
  for (int r = 0; r < k_numRows; r++) {
    pinMode(k_rowPins[r], OUTPUT);
    digitalWrite(k_rowPins[r], HIGH);
  }
  for (int c = 0; c < k_numCols; c++) {
    pinMode(k_colPins[c], INPUT_PULLUP);
  }

  m_callback = callback;
}

void Matrix::loop() {
  for (int r = 0; r < k_numRows; r++) {
    digitalWrite(k_rowPins[r], LOW);
    for (int c = 0; c < k_numCols; c++) {
      if (digitalRead(k_colPins[c]) != m_buttons[r][c].state) {
        if (m_buttons[r][c].debouncer == 0) {
          m_buttons[r][c].debouncer = micros() + k_debounce;
        }
        else if (m_buttons[r][c].debouncer < micros()) {
          m_buttons[r][c].state = !m_buttons[r][c].state;
          m_buttons[r][c].debouncer = 0;
          m_callback(k_returnValues[r][c], !m_buttons[r][c].state);
        }
      }
    }
    digitalWrite(k_rowPins[r], HIGH);
  }
}
