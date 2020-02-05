/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.0                                              */
/*    File: NavMethods.h                                        */
/*    Description: Methods for navigating the robot in auton    */
/*--------------------------------------------------------------*/
#include "RobotConfig.h"
int drivePID();
int trackPosition();
void resetPosition();
void driveToPos(double distance);
void turnToAngle(double angle);
void driveToPosInertial(double distance);
double longitudeError();
double yawError();
extern double maxSpeed;
