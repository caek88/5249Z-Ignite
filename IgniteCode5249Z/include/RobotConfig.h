#ifndef __ROBOTCONFIG_H_INCLUDED__
#define __ROBOTCONFIG_H_INCLUDED__

#include "vex.h"
extern vex::brain Brain;

// define your global instances of motors and other devices here

//This program is for a single stick driven robot
using namespace vex;
extern motor mtrLeft;
extern motor mtrRight;
extern motor mtrLeftFront;
extern motor mtrRightFront;
extern motor mtrArm;
extern motor mtrIntakeLeft;
extern motor mtrIntakeRight;
extern motor mtrRampLift;
extern motor29 speaker;
extern controller ctrPrimary;//Create the controller

//Variables and methods for main file to control competition
static bool colorRed;
static int autonMode;
static competition compControl;

int driver();
int auton();
void deployRobot();
bool liftRamp(bool);
#endif