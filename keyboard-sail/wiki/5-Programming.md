## Set up the programming environment
1. Download Arduino IDE: https://www.arduino.cc/en/Main/Software.
2. Open Arduino IDE.
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
10. Download some of my sample files programs: https://github.com/rpbritton/keyboard-sail/archive/master.zip.