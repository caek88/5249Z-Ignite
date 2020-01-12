#ifndef __ROBOTCONFIG_H_INCLUDED__
#define __ROBOTCONFIG_H_INCLUDED__

#include "vex.h"
extern vex::brain Brain;

//Motors
using namespace vex;
extern motor mtrLeft;
extern motor mtrRight;
extern motor mtrLeftFront;
extern motor mtrRightFront;
extern motor mtrArm;
extern motor mtrIntakeLeft;
extern motor mtrIntakeRight;
extern motor mtrRampLift;

//Other Devices
extern inertial navInert;
extern light cubeBump;
extern controller ctrPrimary;
//extern gyro gyroDrive;

//extern variables
extern bool colorRed;
extern int autonMode;
static competition compControl;
extern double maxSpeed;
extern int originalLight;

//Methods for all source files
void wait(int);
int driver();
int auton();
bool confirmDriver();
bool confirmAuton();
#endif

