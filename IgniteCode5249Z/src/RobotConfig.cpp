#include "vex.h"
using namespace vex;
brain       Brain;

motor mtrLeft = motor(PORT15, false);//Create the motors
motor mtrRight = motor(PORT16, true);
motor mtrLeftFront = motor(PORT11, false);
motor mtrRightFront = motor(PORT20, true);
motor mtrArm = motor(PORT10, true);
motor mtrIntakeLeft = motor(PORT2, false);
motor mtrIntakeRight = motor(PORT9, true);
motor mtrRampLift = motor(PORT4, ratio36_1, false);
motor29 speaker = motor29(Brain.ThreeWirePort.H);
controller ctrPrimary = controller(controllerType::primary);//Create the controller
