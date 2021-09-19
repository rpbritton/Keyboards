#include <Arduino.h>

int currentColumn = 255;

const unsigned int k_baudRate = 250000;

const unsigned char k_colPins[] = {
    9,   8,   7,   6,   3,   5,   4,  10,  18,  19,  20,  21, 255, 255, 255, 255, 255, 
};

void setup(void) {
  for (int i = 0; i < sizeof(k_colPins)/sizeof(k_colPins[0]); i++) {
    if (k_colPins[i] < 255) {
      pinMode(k_colPins[i], OUTPUT);
      digitalWrite(k_colPins[i], LOW);
    }
  }

  Serial1.begin(k_baudRate);
}

void loop(void) {
  while (Serial1.available() == 0) {}
  
  int newColumn = Serial1.read();
  if (newColumn == -1) {
    return;
  }
  
  if (newColumn != currentColumn) {
    digitalWrite(k_colPins[currentColumn], LOW);
    
    if (newColumn < sizeof(k_colPins)/sizeof(k_colPins[0]) && k_colPins[newColumn] < 255) {
      digitalWrite(k_colPins[newColumn], HIGH);
      currentColumn = newColumn;
    } else {
      currentColumn = 255;
    }
  }
  
  Serial1.write(currentColumn);
}
