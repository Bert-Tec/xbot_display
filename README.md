# xbot_display
This repository is about a additional OLED Display for electric scooters using xbot components like ESA 5000 1919 1950 ....

You can use an Arduino Uno for testing. For productive you should use someting smaller like an Arduino pro-mini or ESP-01(s).

For use of ESP-01 please enable it in the xbot_display.ino file, because of custom I2C pins.

<h3>Dependencies (Arduino libraries):<h3>
<ul>
<li>Adafruit_GFX</li>
<li>Adafruit_SSD1306</li>
<li>Wire</li>
</ul>

<h3>How to connect:</h3>

You need to solder three wires to the dashboards lower pins. Power(5V) to the + pin, Ground to the - pin and the serial line to the tr pin. 
<br>
Then connect Arduino/ESP(you need a power converter from 5V to 3.3V for ESP) and Display to power and ground. 
<br>
Then connect serial line to RX pin of Arduino/ESP.
<br>
Then connect I2C cables to OLED and I2C pins(SDA,SCL) of Arduino or to pin 0 and 2 of ESP.
<br>
Now turn on and test it.

<h3>How to Use:</h3>
The display and Arduino/ESP only gets power when the scooter is turned on.
<br>
There are three different display mods at the moment. You can switch between them by pressing full throttle and break for a short moment.

<ul>
<li>Home (Displays throttle and break values in % on top left, Battery % in top right, speed in km?h in the center, left point is eco mode on/off right point is light on/off)</li>
<li>Throttle overview (Here you can test and visualize throttle and break)</li>
<li>OFF (Displays blank screen)</li>
</ul>