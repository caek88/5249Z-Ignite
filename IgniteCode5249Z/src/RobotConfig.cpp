#include "vex.h"
using namespace vex;
brain       Brain;

//Initializations from RobotConfig.h
//Motors
motor mtrLeft = motor(PORT15, false);
motor mtrRight = motor(PORT16, true);
motor mtrLeftFront = motor(PORT11, false);
motor mtrRightFront = motor(PORT20, true);
motor mtrArm = motor(PORT10, true);
motor mtrIntakeLeft = motor(PORT2, false);
motor mtrIntakeRight = motor(PORT9, true);
motor mtrRampLift = motor(PORT4, ratio36_1, false);

//Peripherals
motor29 speaker = motor29(Brain.ThreeWirePort.H);
controller ctrPrimary = controller(controllerType::primary);//Create the controller

encoder encStrafe = encoder(Brain.ThreeWirePort.C);
encoder encLeft = encoder(Brain.ThreeWirePort.E);
encoder encRight = encoder(Brain.ThreeWirePort.G);