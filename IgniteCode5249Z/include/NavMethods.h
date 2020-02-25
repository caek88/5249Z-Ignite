/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.2.0                                            */
/*    File: NavMethods.h                                        */
/*    Description: Methods for navigating the robot in auton    */
/*--------------------------------------------------------------*/
#include "RobotConfig.h"
int drivePID();
void resetPosition();
void driveToPos(double distance);
void turnToAngle(double angle, bool reset = true);
double longitudeError();
double yawError();
extern double maxSpeed;
