# DualBMP
Arduino library allowing for simple functionality of 2 or more BMP180 (barometric pressure) sensors. BMP180 sensors by default all have  the same SPI address, this library configures the sensors manually in order to get around this limitation.

Credits to System via https://forum.arduino.cc/t/how-can-i-add-2-pressure-sensors-bmp180-to-arduino-uno/231589/26
I simply found his implementation and turned it into a header, as needed for another project I'm working on. I figured it would help to make this solution more searchable.

To use:

Sensor 0 SCL Pin = A2
Sensor 0 SDA Pin = A3;
Sensor 1 SCL Pin = A4;
Sensor 1 SDA Pin = A5;
Note: Sensor pins can be changed in DualBMP.cpp.

Download all files to the same directory as your .ino file.
In your main .ino:

     #include "DualBMP.h"
     DualBMP dualbmp;
     
     void setup() {
        Serial.begin(9600);
        while (!Serial) {}; //wait for serial connection to establish
        delay(100);
        dualbmp.beginSense();
        
    void loop() {
      dualbmp.updateSensors();
      dualbmp.printSensorInfo(0);
      dualbmp.printSensorInfo(1);
    }
