#ifndef __ROBOTCONFIG_H_INCLUDED__
#define __ROBOTCONFIG_H_INCLUDED__

#include "vex.h"
extern vex::brain Brain;

// define your global instances of motors and other devices here

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

extern encoder encStrafe;
extern encoder encLeft;
extern encoder encRight;

//Variables and methods for main file to control competition
static bool colorRed;
static int autonMode;
static competition compControl;
static double leftPosition;
static double rightPosition;

int driver();
int auton();
void deployRobot();
bool liftRamp(bool);
int pos();
int drivePID();
void driveToPos(double, double);
//static vex::task driveTask;
//static vex::task positionTask;
extern double xPosition;
extern double yPosition;
static double angle = 0.0;
const double DIAMETER_CHASSIS = 12;
const double DIAMETER_WHEEL = 4;
#endif

