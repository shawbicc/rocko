# esp_bluetooth_demo

A sketch for testing the bluetooth functionality of ESP-32 WROOM devkit v1.

### Arduino IDE Setup

To use the ESP-32 with Arduino IDE:

1.  Go to **File > preferences > Additional boards manager URLs**
2.  Add the following URL for ESP-32: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
    > NOTE: if you already have the ESP8266 boards URL, you can separate the URLs with a comma, as follows:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json, https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

3.  Open the Boards Manager. You can go to **Tools** > **Board** > **Boards Manager…** or you can simply click the **Boards Manager** icon in the left-side corner.
4.  Search for **ESP32** and press the install button for **esp32 by Espressif Systems**.

That’s it. The installation can take a while to complete, depending on the internet speed.

### Uploading sketch to ESP-32

To upload an Arduino sketch to ESP-32:

1.  On the top drop-down menu, select the “unknown” board. A new window, as shown below, will open.
2.  You should select your ESP32 board model and the COM port. In our example, we’re using the **DOIT ESP32 DEVKIT V1** board. Click **OK** when you’re done.
3.  Now, you just need to click on the **Upload** button.

### Testing the Bluetooth serial communication:

1. Open the Serial Monitor. Set BAUD rate to 115200.
2. Pair the ESP-32 device with bluetooth from bluetooth settings on your phone.
3. Install [this app](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&fbclid=IwAR0KXOEqyFW-MfWkENNS8mBvlsQvCqVVRLdlqQbT4GplReGU0sJjvTO7G58&pli=1) on your phone.
4. Open the app and connect the ESP-32.
5. Press and hold a button to configure the name of the button and the string that will be sent via bluetooth to the ESP-32.
6. Press the button. Now you should see the string being printed in the Arduino serial monitor.
