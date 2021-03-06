#ifndef common2_h
#define common2_h

#include "math.h"
#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include "../SoftI2CMaster/SoftI2CMaster.h"

struct floatVec3 {
	float x;
	float y;
	float z;
};

struct sIntVec2{
	short int x;
	short int y;
};

struct sIntVec3{
	short int x;
	short int y;
	short int z;
};
	
void sPrint(floatVec3[], int, bool[], int, sIntVec2);
void sPrint(sIntVec3[], int, bool[], int, sIntVec2);
void sPrintF(float, float, float, bool);
void sPrintI(int, int, int, bool);
/*
Right Hand Grip (Thumb)
+X: Forward (Away)
+Y: Right
+Z: Downwards
*/
floatVec3 calcAngles(floatVec3, floatVec3);
floatVec3 calcAnglesNoRoll(floatVec3, floatVec3);
int MedianOfFive(int, int, int, int, int);
float getEnergySq(floatVec3);
floatVec3 radToDeg(floatVec3);
floatVec3 degToRad(floatVec3);

#endif