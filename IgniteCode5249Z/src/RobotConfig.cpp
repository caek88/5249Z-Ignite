#include "vex.h"
using namespace vex;
brain       Brain;

motor mtrLeft = motor(PORT1, false);//Create the motors
motor mtrRight = motor(PORT10, true);
motor mtrArmLeft = motor(PORT2, false);
motor mtrArmRight = motor(PORT8, true);
motor mtrIntakeLeft = motor(PORT5, false);
motor mtrIntakeRight = motor(PORT9, true);
motor mtrRampLift1 = motor(PORT7, ratio36_1, true);
motor mtrRampLift2 = motor(PORT4, ratio36_1, false);
motor29 speaker = motor29(Brain.ThreeWirePort.H);
controller ctrPrimary = controller(controllerType::primary);//Create the controller