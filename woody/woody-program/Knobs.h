#pragma once

class Knobs {
 public:
  Knobs();
  void setup(void (*callback)(unsigned char));
  void loop();
  
 private:
  static const unsigned char k_ctrlPin = 0;
 
  static const unsigned char k_numKnobs = 3;
 
  const unsigned char k_knobPins[k_numKnobs][2] = {
    {8, 14}, {15, 7}, {21, 16}
  };

  const unsigned char k_returnValues[k_numKnobs][2] = {
     {93, 92}, {91, 90}, {89, 88},
  };
 
  enum KnobState {
    NOT_TURNING,
    WAITING_TO_FLIP,
    WAITING_TO_STOP
  };

  enum TurnType {
    CW,
    CCW
  };

  struct Knob {
    KnobState state;
    TurnType turn;
  };

  Knob m_knobs[k_numKnobs];

  void (*m_callback)(unsigned char);
};
