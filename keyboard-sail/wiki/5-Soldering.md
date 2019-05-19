## Soldering basics
1. Be safe. Wear safety glasses and don't touch the hot end.
2. Touch the solder, soldering iron tip, and the connection you want to solder together.
3. Here is an example of a good and bad solder joints:
![](https://cdn-learn.adafruit.com/assets/assets/000/001/978/medium800/tools_Header_Joints.jpg)
<sup>[Image Credit](https://learn.adafruit.com/adafruit-guide-excellent-soldering/common-problems)</sup>
4. Don't touch it for too long or you may melt the switch, causing it to break.
## Think about your matrix
* Split up your layout into rows and columns
* ***Make sure the sum of the number of columns and rows is less than or equal to 20.***
* Here is an example of a standard 104 key layout:   
![](https://npx3.files.wordpress.com/2016/01/standardwiring.png)   
<sup>[Image Credit](https://npx3.wordpress.com/2016/01/28/the-blue-pill-option-building-a-keyboard-part-4/)</sup>     
**Go slowly. If you don't do a good job because you rushed, it will take more time to find the problems than if you hadn't.**
## Diodes / Rows
1. ***Always check first to make sure your diodes work with a multimeter.***
2. Make each row look like this using wirecutters and tweezers. I strongly urge you to ask if you don't understand why you should wire it this way.   
![](https://i.imgur.com/mAfs39u.jpg)
3. Solder the red spots. I'd recommend soldering the switch pins first, and then adding solder between the diode leads. Creating a "hook" or twisting them together will help create a better solder joint.
## Columns
1. With wire strippers, remove all of the rubber from the single-core wire. You should be left with a long piece of exposed wire.
2. Measure out wire to connect the top and bottom switches of a column based on the other (unused) switch pin and cut it to length.
2. Cover the parts of the wire that do not connect with the switch pins so it resembles this:
![](https://i.imgur.com/oEeDrEj.jpg)   
3. Hook the ends wrap around the top and bottom pins. The final thing should look like this:   
![](https://i.imgur.com/dLgxQ5i.jpg)
4. Add solder to each contact.
## Connecting it to the microcontroller
1. Observe the image below. All the pins labeled with a blue number are GPIO capable. Choose the number you need for your matrix (sum of rows and columns). If you plan on using indicator lights leave 1 "red" (PWM) pin for each LED.   
![](https://cdn.sparkfun.com/assets/9/c/3/c/4/523a1765757b7f5c6e8b4567.png)   
<sup>[Image Credit](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/hardware-overview-pro-micro)</sup>
2. Run 1 wire on each column and row to any of the selected pins.
## Indicator LEDs
1. ***Always check to see if the led works with a resistor and a multimeter.***
2. Position each LED wherever you want them.
3. Connect the longer of the two leads to a resistor.
4. Connect the other lead of the resistor to the RAW pin (look at the pinout diagram of the Pro Micro above).
5. Connect the shorter of the two leads to a GPIO that is marked "red" (PWM).
6. Do this for every LED (but choose different GPIOs).