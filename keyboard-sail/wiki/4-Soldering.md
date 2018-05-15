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
3. I'd recommend soldering the switch pins first, and then adding solder between the diode leads. Creating a "hook" or twisting them together will help create a better solder joint.
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
1. ***Always check to see if the led works with a resistor and a multimeter.***
2. Position each LED wherever you want them.
3. Connect the longer of the two leads to a resistor.
4. Connect the other lead of the resistor to the RAW pin (look at the pinout diagram of the Pro Micro above).
5. Connect the shorter of the two leads to a GPIO that is marked "red" (PWM).
6. Do this for every LED (but choose different GPIOs).