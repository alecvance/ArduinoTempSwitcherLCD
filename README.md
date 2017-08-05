This Arduino project checks the temperature and turns on an outlet using a relay when the temperature has exceeded the upper limit of a defined range, then turns it off again when the sensor has reached the bottom temperature of the defined range.

It uses an Arduino Uno, an LCD module for display, a temperature/humidity sensor, and a relay.

This was designed for a beer fermenter refrigerator, so that we can simply power on/off the appliance according to the inside temperature without altering any of the electronics on the fridge.


Arduino LCD
RioRand® LCD Module for Arduino 20 x 4, White on Blue
https://www.amazon.com/RioRand-Module-Arduino-White-Blue/dp/B00GZ6GK7A/ref=cm_rdp_product

Pin # Function
1 VSS (Gnd)
2 VDD (+5V)
3 Contrast Adjustment - Connect the center tap of a 10k pot connected between Gnd and 5V
4 RS Register Select Input
5 R/W Read/Write Signal, normally at Gnd
6 E Enable
7 DB0
8 DB1
9 DB2
10 DB3
11 DB4
12 DB5
13 DB6
14 DB7
15 LED (+) (+5V through a current limiting resistor - I used 220ohm)
16 LED (-) Gnd

The Arduino connections are as follows:
LCD Pin: Arduino Pin:
RS D12
E D11
DB4 D5
DB5 D4
DB6 D3
DB7 D2


————

Project Breadboard. 
All Arduino pins are Digital.

LCD screen pin outs
1. black wire to breadboard: Left Side of 10K pot. also jumped to - rail
2. orange wire to breadboard: right side of 10K pot. also jumped to + rail
3. yellow/black wire to breadboard: center of 10K pot
4.  yellow wire to arduino pin 12
5. orange wire to arduino GND
6. brown wire to arduino pin 11
7. not used
8. not used
9. not used
10. not used
11. white wire to arduino pin 5
12. green wire to arduino pin 4
13. purple wire to arduino pin 3
14. blue wire to arduino pin 2
15. red wire to breadboard: resistor (200K??) to + rail
16. brown wire to breadboard: - rail

Temp/Humidity Sensor pin outs
DAT pin to arduino pin 8
VCC pin to + rail
GND pin to - rail

Relay
https://www.amazon.com/RobotDyn-Thyristor-channel-Switch-Solid/dp/B072WQTBPQ/ref=sr_1_16?ie=UTF8&qid=1499537292&sr=8-16&keywords=solid+state+relay+5v+arduino

VCC connected to relay pin 13
GND connected to - rail

