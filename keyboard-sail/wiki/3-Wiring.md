* Circuits (in this simple case) can be high (VCC), low (GND), or floating. Same voltage throughout (5V).
* Controller has GPIOs (**G**eneral **P**urpose **I**nput **O**utput pins).
* Output pins are set to high or low.
* Input pins are pulled high with a resistor, pulled low with a resistor, or floating.
* This creates a weak logic value that can be overrun by a stable connection.
* Back to mechanical keyboards, most switches will connect two contacts.
* So an input pin pulled high connected to a switch (push button) that is connected to GND on its 2nd pin will read high when the switch is not pressed and low when it is.
* The input pin can also be pulled low and the switch connected to VCC for flipped results.
* The Pro Micro has 21 GPIOs, so enough for 21 switches, unless you use a key matrix.