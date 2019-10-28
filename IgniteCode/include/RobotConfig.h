#ifndef __ROBOTCONFIG_H_INCLUDED__
#define __ROBOTCONFIG_H_INCLUDED__

#include "vex.h"
using namespace vex;
// A global instance of vex::brain used for printing to the V5 brain screen
static brain Brain;
static competition compControl = competition();

// define your global instances of motors and other devices here
static controller ctrPrimary = controller(controllerType::primary);

//Variables and methods for main file to control competition
static bool colorRed;
static int autonMode;
#endif