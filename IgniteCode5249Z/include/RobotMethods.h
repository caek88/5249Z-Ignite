/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.2.0                                            */
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
void setOriginalLight();

bool liftRamp(bool moveUp, double slow = 50, double fast = 100);
