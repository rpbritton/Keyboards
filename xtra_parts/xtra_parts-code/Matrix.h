#pragma once

class Matrix {
 public:
  Matrix() {};
  void setup(void (*callback)(unsigned char, bool));
  void loop();

 private:
  static const unsigned long k_debounce = 5000;
  
  static const unsigned char k_numRows = 15;
  static const unsigned char k_numCols = 5;

  const unsigned char k_rowPins[k_numRows] = {
    14, 15, 16, 17, 18, 19, 20, 21, 1, 2, 3, 4, 5, 6, 7
  };
   const unsigned char k_colPins[k_numCols] = {
    0, 13, 23, 10, 9
  };
  
   const unsigned char k_returnValues[k_numRows][k_numCols] = {
    {  0,  14,  28,  41,  53  },
    {  1,  15,  29, 255,  54  },
    {  2,  16,  30,  42, 255  },
    {  3,  17,  31,  43,  55  },
    {  4,  18,  32,  44, 255  },
    {  5,  19,  33,  45, 255  },
    {  6,  20,  34,  46, 255  },
    {  7,  21,  35,  47,  56  },
    {  8,  22,  36,  48, 255  },
    {  9,  23,  37,  49, 255  },
    { 10,  24,  38,  50,  57  },
    { 11,  25,  39,  51,  58  },
    { 12,  26, 255,  52,  60 },
    { 13,  27,  40,  59,  61 },
    { 63, 255,  64,  65,  62 },
  };
 
  struct Button {
    unsigned long debouncer = 0;
    bool state = HIGH;
  };

  Button m_buttons[k_numRows][k_numCols];

  void (*m_callback)(unsigned char, bool);
};
