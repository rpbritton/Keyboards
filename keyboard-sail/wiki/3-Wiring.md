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
6. Check the next row and repeat.

![](https://i.stack.imgur.com/No6u5.gif)

https://electronics.stackexchange.com/questions/114993/pressing-same-key-rows-at-the-same-time

## Diodes
* They only let current flow one way: **from anode to cathode. The black end of the diode is the cathode.**
* They are used to prevent ghosting (when a switch appears pressed when it isn't).

<img width="300px" src="http://blog.komar.be/wp-content/uploads/2013/09/e.png">
<img width="300px" src="http://blog.komar.be/wp-content/uploads/2013/09/f.png">

http://blog.komar.be/how-to-make-a-keyboard-the-matrix/
## LEDs
* LEDs actually work like diodes (**L**ight **E**mitting _**D**iodes_).
* The longer lead is is the anode, so **the positive voltage must be applied there.**
* They will eat up all the current and burn out, so you must add a resistor to limit it.
* Here's what the circuit looks like:   
![](https://upload.wikimedia.org/wikipedia/commons/c/c9/LED_circuit.svg)   
https://en.wikipedia.org/wiki/LED_circuit
# Physical Wiring
## Think about your matrix
* Split up your layout into rows and columns
* ***Make sure the sum of the number of columns and rows is less than or equal to 20.***
* Here is an example of a standard 104 key layout:   
![](https://npx3.files.wordpress.com/2016/01/standardwiring.png)   
https://npx3.wordpress.com/2016/01/28/the-blue-pill-option-building-a-keyboard-part-4/
## Diodes / Rows
1. ***Always check first to make sure your diodes work with a multimeter.***
2. Make each row look like this using wirecutters and tweezers. I strongly urge you to ask if you don't understand why you should wire it this way.   
![](https://i.imgur.com/mAfs39u.jpg)
3. Add solder to the switch pins first, then add solder between the diode leads. Creating a "hook" or twisting them together will help the solder joint.
## Columns
1. Measure out wire to connect the top and bottom switches of a column based on the other (unused) switch pin.
2. Expose the parts of the wire that will touch the pins of the switches like this:
![](https://i.imgur.com/oEeDrEj.jpg)   
3. Hook the ends wrap around the top and bottom pins. It should look like this:   
![](https://i.imgur.com/dLgxQ5i.jpg)
4. Add solder to each contact.
## Connecting it to the microcontroller
1. Observe the image below:   
![](https://cdn.sparkfun.com/assets/9/c/3/c/4/523a1765757b7f5c6e8b4567.png)   
https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/hardware-overview-pro-micro   
All the pins labeled with a blue number are GPIO capable. Choose the number you need for your matrix (sum of rows and columns). Avoid pins '1' and '0', and if you plan on using indicator lights leave 1 "red" (PWM) pin for each LED.
2. Run 1 wire on each column and row to any of the selected pins.
## Indicator LEDs
1. Check to see if the led works with a resistor and a multimeter.
2. Position each LED whereever you want them.
3. Connect the longer of the two leads to a resistor.
4. Connect the other lead of the resistor to the RAW pin (look at the pinout diagram of the Pro Micro above).
5. Connect the shorter of the two leads to a GPIO that is marked "red" (PWM).
6. Do this for every LED (but choose different GPIOs).