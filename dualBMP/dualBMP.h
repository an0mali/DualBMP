//Contains functions for reading from and interpreting BMP180 data from 2 sensors on the same SPI port.
// Credits to System via https://forum.arduino.cc/t/how-can-i-add-2-pressure-sensors-bmp180-to-arduino-uno/231589/26
// Code has been converted into library and some strings removed to reduce memory consumption

#ifndef DualBMP_h
#define DualBMP_h
#include "MyWireLib.h"
#include <Arduino.h>

class DualBMP {
  public:
    DualBMP();
    void updateSensors();
    void beginSense();
    void printSensorInfo(int eachsens);
    float T[2], P[2];//Temp, Pressure
  
  private:
    void init_SENSOR(int sensnr);
    float pressure(int32_t b5, int sensnr);
    int32_t temperature(int sensnr);
    int32_t read_pressure(int sensnr);   
    const uint8_t oss = 3;                      // Set oversampling setting
    const uint8_t osd = 26;                     // with corresponding oversampling delay
    int16_t  ac1[2], ac2[2], ac3[2], b1[2], b2[2], mb[2], mc[2], md[2]; // Store sensor PROM values from BMP180
    uint16_t ac4[2], ac5[2], ac6[2];                     // Store sensor PROM values from BMP180 
    
    MyWireLib Sens[2];
    
};

#endif
