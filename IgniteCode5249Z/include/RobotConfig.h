/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.0                                              */
/*    File: RobotConfig.h                                       */
/*    Description: Defines the global variables for the program */
/*      and methods for the main program                        */
/*--------------------------------------------------------------*/
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
extern limit limArm;
extern limit limRamp;
extern limit limArmBottom;
extern controller ctrPrimary;
//extern gyro gyroDrive;

//extern variables
extern bool colorRed;
extern int autonMode;
static competition compControl;

//Methods for all source files
void wait(int);
int driver();
int auton();
bool confirmDriver();
bool confirmAuton();
#endif

