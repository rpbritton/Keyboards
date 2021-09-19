#pragma once

class Matrix {
 public:
  Matrix() {};
  void setup(void (*callback)(unsigned char, bool));
  void loop();

 private:
  void setSlave(unsigned char column);
 
  static const unsigned int k_baudRate = 250000;
  static const unsigned long k_debounce = 5000;
  
  static const unsigned char k_numRows = 6;
  static const unsigned char k_numCols = 17;

  const unsigned char k_rowPins[k_numRows] = {
      4,   3,   2,  19,  18,  15,
  };
   const unsigned char k_colPins[k_numCols] = {
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  20,  21,   9,   8,   7,
  };
  
   const unsigned char k_returnValues[k_numRows][k_numCols] = {
    {   0,   1,   2,   3,   4,   5,   6,   7,   8, 255,   9,  10,  11,  12,  13,  14,  15 },
    {  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32 },
    {  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49 },
    {  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61, 255,  62, 255, 255, 255 },
    {  63,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73, 255, 255,  74, 255,  75, 255 },
    {  76,  77,  78, 255, 255,  79, 255, 255,  80, 255,  81,  82, 255,  83,  84,  85,  86 },
  };
 
  struct Button {
    unsigned long debouncer = 0;
    bool pressed = false;
  };

  Button m_buttons[k_numRows][k_numCols];

  void (*m_callback)(unsigned char, bool);
};
