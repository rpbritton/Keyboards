## Set up the programming environment
1. Download Arduino IDE: https://www.arduino.cc/en/Main/Software.
2. Install and open Arduino IDE.
3. Go to **File** > **Preferences**.
4. Copy and paste the following URL into the **Additional Board Manager URLs** box:
```
https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json
```
5. Click **OK** and go to **Tools** > **Board: ...** > **Board Manager...**
6. Search for `SparkFun AVR Boards` and click **Install**.
7. Click **Close** and go back to **Tools** > **Board: ...** and scroll down until you find `SparkFun Pro Micro`.
8. Next go to **Sketch** > **Include Library** > **Manage Libraries...**
9. Search for `keyboard` and install `HID by Arduino`, `Keyboard by Arduino`, and `Mouse by Arduino`.
10. Download the sample programs: https://github.com/rpbritton/keyboard-sail/archive/master.zip.
## Basics of Arduino Programming   
It's in the 'c' programming language. The basic setup as follows:
1. Add your includes.
2. Create your global variables.
3. `setup()` runs once at the beginning to configure stuff like your GPIO pins.
4. `loop()` is called after `setup()` and then everytime it ends (like a `while (true)` loop).
## Test it out
1. Open `blinky.ino`. Read through the comments to get a feel of what is going on.
2. Click **Verify** to check if the code compiles.
3. If that works, click **Upload**. The controller LEDs should flash a few times and then one of them should start blinking at an interval.