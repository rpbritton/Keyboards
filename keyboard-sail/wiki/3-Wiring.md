# Background Knowledge
## The Basics
* Circuits (in this simple case) can be high (VCC), low (GND), or floating. It's the same voltage throughout (5V).
* Controller has GPIOs (**G**eneral **P**urpose **I**nput **O**utput pins).
   * Output pins are set to high or low.
   * Input pins are pulled high with a resistor or left floating.
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
![](https://i.stack.imgur.com/No6u5.gif)   
https://electronics.stackexchange.com/questions/114993/pressing-same-key-rows-at-the-same-time   
#### Diodes, which only lets current flow one way, are used to prevent ghosting (when a switch appears pressed when it isn't).   
![](http://blog.komar.be/wp-content/uploads/2013/09/e.png)   
http://blog.komar.be/how-to-make-a-keyboard-the-matrix/
# Physical Wiring
## Thinking about your matrix
* Split up your layout into rows and columns
* ***Make sure the sum of the number of columns and rows is less than or equal to 20.***
## Diodes / Rows
1. ***Always check first to make sure your diodes work***