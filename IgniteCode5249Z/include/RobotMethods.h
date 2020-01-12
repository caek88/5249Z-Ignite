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
bool liftRamp(bool, double slow = 15, double fast = 50, bool outtake = false);
void stackTower(bool waitForCubes = true);