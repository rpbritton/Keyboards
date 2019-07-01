#pragma once

class Matrix {
 public:
  Matrix() {};
  void setup(void (*callback)(unsigned char, bool));
  void loop();

 private:
  static const unsigned long k_debounce = 5000;
  
  static const unsigned char k_numRows = 10;
  static const unsigned char k_numCols = 9;

  const unsigned char k_rowPins[k_numRows] = {
    1, 2, 4, 3, 5, 6, 23, 13, 22, 12
  };
   const unsigned char k_colPins[k_numCols] = {
    19, 20, 18, 21, 16, 7, 15, 14, 8
  };
  
   const unsigned char k_returnValues[k_numRows][k_numCols] = {
    {  0,   2,   4,   6,   8,  10,  12,  14,  16 },
    {  1,   3,   5,   7,   9,  11,  13,  15,  33 },
    { 17,  19,  21,  23,  25,  27,  29,  32,  50 },
    { 18,  20,  22,  24,  26,  28,  30,  31,  49 },
    { 34,  36,  38,  40,  42,  44,  46,  48,  87 },
    { 35,  37,  39,  41,  43,  45,  47,  76,  86 },
    { 51,  53,  55,  57,  59,  61,  63, 255,  85 },
    { 52,  54,  56,  58,  60,  62,  75, 255,  84 },
    { 64,  65,  66,  68,  69,  71,  73,  74,  83 },
    { 77,  78,  79,  67,  80,  70,  72,  81,  82 },
  };
 
  struct Button {
    unsigned long debouncer = 0;
    bool state = HIGH;
  };

  Button m_buttons[k_numRows][k_numCols];

  void (*m_callback)(unsigned char, bool);
};
