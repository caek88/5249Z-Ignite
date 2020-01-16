/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.0                                              */
/*    File: RobotMethods.h                                      */
/*    Description: Methods for controlling different parts of   */
/*        the robot                                             */
/*--------------------------------------------------------------*/
#include "RobotConfig.h"
void intake(double speed);
void intakeStop(brakeType stopMode = brakeType::coast);
void chassisLeft(double speed);
void chassisRight(double speed);
void arm(double speed);
void armStop(brakeType stopMode = brakeType::coast);
void rampLift(double speed);
void rampLiftStop(brakeType stopMode = brakeType::coast);
bool cubesClear();

void deployRobot();
bool liftRamp(bool moveUp, double slow = 15, double fast = 50, bool outtake = false);
void stackTower(bool waitForCubes = true);

extern int originalLight;
