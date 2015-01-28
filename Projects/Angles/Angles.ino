#include <Wire.h>
#include "common2.h"
#include "SoftI2CMaster.h"
#include "I2CDevice.h"
#include "ADXLAccelerometer.h"
#include "HMCCompass.h"

#define BAUDRATE 14400
#define SENSORCOUNT 3
#define SCL 2
#define SDA1 3
//Default: A4 SDA, A5 SCL
//static Compass compass1 = Compass(3, 2);
static Compass compass[SENSORCOUNT];
static Accelerometer accel[SENSORCOUNT];
//static Accelerometer accel = Accelerometer(3, 4);

void setup(){
  Serial.begin(14400);//Recommended 19200
  Wire.begin();
  for (int i = 0; i < SENSORCOUNT; i++){
    accel[i] = Accelerometer(SDA1 + i, SCL);
    accel[i].init();
    compass[i] = Compass(SDA1 + i, SCL);
    compass[i].init();
  }
}

void loop(){
  float x;
  float y;
  for (int i = 0; i < SENSORCOUNT; i++){
    threeD acc = accel[i].getVal();
    threeD mag = compass[i].getVal();
    threeD rot = calcAngles(acc, mag);
    //sPrint(acc.x, acc.y, acc.z, false);
    //sPrint(mag.x, mag.y, mag.z, false);
    //sPrint(rot.x, rot.y, rot.z, true);
    if (i == SENSORCOUNT - 1)
      sPrint(rot.x, rot.y, rot.z, true);
    else sPrint(rot.x, rot.y, rot.z, false);
  }
}
