## The Fundamentals
* Circuits (in this simple case) can be high (VCC), low (GND), or floating. It's the same voltage throughout (5V).
* The controller has GPIOs (**G**eneral **P**urpose **I**nput **O**utput pins).
   * Output pins are set to high or low.
   * Input pins are internally pulled high with a resistor or left floating.
      * This creates a "weak" logic value that can be overrun by a direct connection.
* Back to mechanical keyboards, most switches will create a connection between two contacts when pressed.
* So an input pin pulled high will read high unless the switch (connected to GND) is pressed.
* The Pro Micro has 21 GPIOs, which is enough for 21 inputs (thus 21 switches), unless we use a key matrix.
## Key Matrix
1. Connect each row and each column to a pin.
2. Set all the rows to be high outputs.
3. Set all the columns to be pulled high inputs.
4. Set one row to low and check the column pins.
5. If a column pin is low you know that switch is pressed.   
6. Check the next row and repeat.   
![](https://i.stack.imgur.com/No6u5.gif)   
<sup>[Image Credit](https://electronics.stackexchange.com/questions/114993/pressing-same-key-rows-at-the-same-time)</sup>

## Diodes
* Only let current flow one way: **from anode to cathode. The black end of the diode is the cathode.**
* Used to prevent ghosting (when a switch appears pressed when it isn't).

<img width="300px" src="http://blog.komar.be/wp-content/uploads/2013/09/e.png">
<img width="300px" src="http://blog.komar.be/wp-content/uploads/2013/09/f.png">

<sup>[Images Credit](http://blog.komar.be/how-to-make-a-keyboard-the-matrix/)</sup>
## LEDs
* LEDs actually work like diodes (**L**ight **E**mitting _**D**iodes_).
* The longer lead is the anode, so **the positive voltage must be applied there.**
* They will eat up all the current and burn out, so you must add a resistor to limit it.
* Here's what the circuit looks like:   
![](https://upload.wikimedia.org/wikipedia/commons/c/c9/LED_circuit.svg)   
<sup>[Image Credit](https://en.wikipedia.org/wiki/LED_circuit)</sup>