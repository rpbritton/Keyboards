#include <Arduino.h>

#include "Knobs.h"

Knobs::Knobs() {
  
}

void Knobs::setup(void (*callback)(unsigned char)) {
  pinMode(k_ctrlPin, OUTPUT);
  digitalWrite(k_ctrlPin, HIGH);

  for (int k = 0; k < k_numKnobs; k++) {
    pinMode(k_knobPins[k][CCW], INPUT_PULLUP);
    pinMode(k_knobPins[k][CW], INPUT_PULLUP);
  }

  m_callback = callback;
}

void Knobs::loop() {
  digitalWrite(k_ctrlPin, LOW);
  
  for (int k = 0; k < k_numKnobs; k++) {
    bool ccwBtn = digitalRead(k_knobPins[k][CCW]);
    bool cwBtn = digitalRead(k_knobPins[k][CW]);

    if (ccwBtn == HIGH && cwBtn == HIGH) {
      if (m_knobs[k].state == WAITING_TO_STOP) {
        m_callback(k_returnValues[k][m_knobs[k].turn]);
      }
      m_knobs[k].state = NOT_TURNING;
    }
    else if (ccwBtn == HIGH && cwBtn == LOW) {
      if (m_knobs[k].state == WAITING_TO_FLIP && m_knobs[k].turn == CCW) {
        m_knobs[k].state = WAITING_TO_STOP;
      }
      else if (m_knobs[k].state == NOT_TURNING) {
        m_knobs[k].state = WAITING_TO_FLIP;
        m_knobs[k].turn = CW;
      }
    }
    else if (ccwBtn == LOW && cwBtn == HIGH) {
      if (m_knobs[k].state == WAITING_TO_FLIP && m_knobs[k].turn == CW) {
        m_knobs[k].state = WAITING_TO_STOP;
      }
      else if (m_knobs[k].state == NOT_TURNING) {
        m_knobs[k].state = WAITING_TO_FLIP;
        m_knobs[k].turn = CCW;
      }
    }
  }
  
  digitalWrite(k_ctrlPin, HIGH);
}
