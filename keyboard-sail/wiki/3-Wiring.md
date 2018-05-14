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
* They only let current flow one way: **towards the black end, but not against it.**
* They are used to prevent ghosting (when a switch appears pressed when it isn't).

<img width="300px" src="http://blog.komar.be/wp-content/uploads/2013/09/e.png">
<img width="300px" src="http://blog.komar.be/wp-content/uploads/2013/09/f.png">

http://blog.komar.be/how-to-make-a-keyboard-the-matrix/
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
