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
extern gyro driveGyro;
extern light cubeBump;
extern controller ctrPrimary;
extern encoder encStrafe;
extern encoder encLeft;
extern encoder encRight;

//extern variables
extern bool colorRed;
extern int autonMode;
static competition compControl;
extern double leftPosition;
extern double rightPosition;
extern double xPosition;
extern double yPosition;
extern double maxSpeed;
extern int originalLight;

//Methods for all source files
void intake(double speed);
void intakeStop(brakeType stopMode = brakeType::coast);
void chassisLeft(double speed);
void chassisRight(double speed);
void arm(double speed);
void armStop(brakeType stopMode = brakeType::coast);
void rampLift(double speed);
void rampLiftStop(brakeType stopMode = brakeType::coast);

void wait(int);
int driver();
int auton();
bool confirmDriver();
bool confirmAuton();
void deployRobot();
bool liftRamp(bool, double slow = 15, double fast = 50);
int drivePID();
void driveToPos(double distance);
bool turnToAngle(double finalAngle, double tolerance = 2.5);
void stackTower(int, bool ejectDown = false);
#endif

