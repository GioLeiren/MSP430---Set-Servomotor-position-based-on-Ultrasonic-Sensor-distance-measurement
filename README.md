# MSP430 - Set Servomotor position based on Ultrasonic Sensor distance measurement
## Overview
This project contains a C code that configures the **MSP430F5529**, the ultrassonic sensor **HC-SR04** and a servomotor to measure distance and based on it, turn on/off the red and green LEDs from the MSP430 and set the servomotor position. Below there's a graph that contains the relationship between the distance measured and the servo position.  
![cm distance to degrees](https://i.imgur.com/ZbiZb2x.png)  
Additionally, we can set up the MSP's LEDs to enhance the distance measurement. Below there's a table that shows the red and green LEDs states based on the measured distance  
![LEDs states](https://i.imgur.com/mSlfSnr.png)  
## Configuration steps
MSP configuration steps used on the project:
* Servomotor
  * Plug the servomotor's brown cable into a MSP430 GND pin;
  * Plug the servomotor's red cable into a MSP430 5V pin;
  * Plug the servomotor's orange cable into the MPS430 1.2 pin.
* HC-SR04 sensor
  * Plug the device onto a protoboard
  * Connect a cable into the corresponding spot of the HC-SR04 **Vcc** pin and plug it into a MSP430 5V pin;
  * Connect a cable into the corresponding spot of the HC-SR04 **Trigger** pin and plug it into the MSP430 1.4 pin;
  * Connect two resistors (preferably 4,7KΩ and 10KΩ) into the corresponding spot of the HC-SR04 **Echo**(to avoid MSP430 pin burn), connect a cable at the ending of the resistor and plug it into the MSP430 1.5 pin.
  * Connect a cable into the corresponding spot of the HC-SR04 **GND** pin and plug it into a MSP430 GND pin;
