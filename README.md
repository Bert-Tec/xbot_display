# xbot_display
This repository is about a additional OLED Display for electric scooters using xbot components like ESA 5000 1919 1950 ....

You can use an Arduino Uno for testing. For productive you should use someting smaller like an Arduino pro-mini or ESP-01(s).

For use of ESP-01 please enable it in the xbot_display.ino file, because of custom I2C pins.

![V1](/img/v1_1.jpg)
![V1](/img/v1_3.jpg)

3D printed spacer which also puts the dashboard up, so that it looks good. And so you can secure the spacer with the screws of the dashboard(you'll need new M2x12 screws!):
![V2](/img/v2_1.jpg)
![V2](/img/v2_2.jpg)


<h3>Dependencies (Arduino libraries):</h3>
<ul>
<li>Adafruit_GFX</li>
<li>Adafruit_SSD1306</li>
<li>Wire</li>
</ul>

<h3>Hardware needed:</h3>
<ul>
<li>1.3"(0.96"works also) OLED display (Yellow/Blue or White)</li>
<li>Arduino pro mini 5V OR ESP-01(s) AND 5V to 3.3V converter</li>
<li>Cables, isolation tape and a small resistor (like 220R)</li>
<li>3D printed spacer(see 3D folder, you'll need 3 new M2x12 screws to secure it well) or mod a housing on your own</li>
<li>optional some hot glue to hold stuff in place</li>
</ul>

<h3>How to connect:</h3>

You need to solder three wires to the dashboards lower pins. Power(5V) to the + pin, Ground to the - pin and the serial line to the tr pin. 
<br>
Then connect Arduino/ESP(you need a power converter from 5V to 3.3V for ESP) and Display to power and ground. 
<br>
Then connect serial line to RX pin of Arduino/ESP and using a resistor (for best work a diode) to TX.
<br>
Then connect I2C cables to OLED and I2C pins(SDA,SCL) of Arduino or to pin 0 and 2 of ESP.
<br>
Now turn on and test it.

<h3>How to Use:</h3>
The display and Arduino/ESP only gets power when the scooter is turned on.
<br>
You can switch to max. speed of 30 kmh by holding break and throttle for 7 seconds and at speed of 0. For reset hold break and throttle for 2 seconds and at speed of 0.
There are three different display mods at the moment. You can switch between them by pressing full throttle for 0.75 second at speed of 0:

<ul>
<li>Home (Displays throttle and break values in % on top left, Battery % in top right, speed in km/h in the center, left point is eco mode on/off right point is light on/off and the middle is 30km/h mode on/off)</li>
<li>Throttle overview (Here you can test and visualize throttle and break)</li>
<li>OFF (Displays blank screen)</li>
</ul>

<h3>Future Features:</h3>
<ul>
<li>Trip meter</li>
<li>unlock speed - done</li>
<li>view aditional informations</li>
</ul>

<h1>Disclaimer</h1>
Use on your own risk.
Not street legal in Germany!!!

<h3>Protocol informations:</h3>

![Serial](/serial/serial_protocol.txt)