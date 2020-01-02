#include "vex.h"
#include "RobotConfig.h"
using namespace vex;
brain Brain;

//Initializations from RobotConfig.h
//Motors
motor mtrLeft = motor(PORT15, false);
motor mtrRight = motor(PORT16, true);
motor mtrLeftFront = motor(PORT11, false);
motor mtrRightFront = motor(PORT20, true);
motor mtrArm = motor(PORT10, ratio36_1, true);
motor mtrIntakeLeft = motor(PORT2, true);
motor mtrIntakeRight = motor(PORT8, false);
motor mtrRampLift = motor(PORT4, ratio36_1, false);

//Peripherals
light cubeBump = light(Brain.ThreeWirePort.A);
gyro driveGyro = gyro(Brain.ThreeWirePort.H);
controller ctrPrimary = controller(controllerType::primary);//Create the controller

//extern variables
double maxSpeed = 80;
bool colorRed;
int autonMode;
int originalLight;