#ifndef __ROBOTCONFIG_H_INCLUDED__
#define __ROBOTCONFIG_H_INCLUDED__

#include "vex.h"
vex::brain       Brain;

// define your global instances of motors and other devices here

//This program is for a single stick driven robot
using namespace vex;
motor mtrLeft = motor(PORT1, false);//Create the motors
motor mtrRight = motor(PORT10, true);
motor mtrArmLeft = motor(PORT2, false);
motor mtrArmRight = motor(PORT8, true);
motor mtrIntakeLeft = motor(PORT3, false);
motor mtrIntakeRight = motor(PORT9, true);
motor mtrRampLift1 = motor(PORT7, ratio36_1, true);
motor mtrRampLift2 = motor(PORT4, ratio36_1, false);
motor29 speaker = motor29(Brain.ThreeWirePort.H);
controller ctrPrimary = controller(controllerType::primary);//Create the controller

//Variables and methods for main file to control competition
static bool colorRed;
static int autonMode;
static competition compControl;
#endif