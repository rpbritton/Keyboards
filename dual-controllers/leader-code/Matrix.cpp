#include <Arduino.h>

#include "Matrix.h"

void Matrix::setup(void (*callback)(unsigned char, bool)) {
  m_callback = callback;
  
  for (int r = 0; r < k_numRows; r++) {
      pinMode(k_rowPins[r], INPUT);
  }
  for (int c = 0; c < k_numCols; c++) {
    if (k_colPins[c] != 255) {
      pinMode(k_colPins[c], OUTPUT);
      digitalWrite(k_colPins[c], LOW);
    }
  }

  for (int r = 0; r < k_numRows; r++) {
    for (int c = 0; c < k_numCols; c++) {
      m_buttons[r][c].debouncer = 0;
      m_buttons[r][c].pressed = false;
    }
  }

  Serial1.begin(k_baudRate);
}

void Matrix::setSlave(unsigned char column) {
  while (Serial1.available() > 0) { Serial1.read(); }
  Serial1.write(column);  
  while (Serial1.available() == 0) {}
}

void Matrix::loop() {
  for (int c = 0; c < k_numCols; c++) {
    setSlave(c);
    if (k_colPins[c] != 255) {
      digitalWrite(k_colPins[c], HIGH);
    }
    
    for (int r = 0; r < k_numRows; r++) {
      if ((digitalRead(k_rowPins[r]) == HIGH) != m_buttons[r][c].pressed) {
        if (m_buttons[r][c].debouncer == 0) {
          m_buttons[r][c].debouncer = micros();
        } else if (micros() - m_buttons[r][c].debouncer > k_debounce) {
          m_buttons[r][c].pressed = !m_buttons[r][c].pressed;
          m_buttons[r][c].debouncer = 0;
          
          m_callback(k_returnValues[r][c], m_buttons[r][c].pressed);
        }
      } else {
        m_buttons[r][c].debouncer = 0;
      }
    }
    
    if (k_colPins[c] != 255) {
      digitalWrite(k_colPins[c], LOW);
    }
  }
}
