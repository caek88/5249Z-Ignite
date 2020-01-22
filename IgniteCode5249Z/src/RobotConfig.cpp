/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.0                                              */
/*    File: RobotConfig.cpp                                     */
/*    Description: Instantiates extern objects in RobotConfig.h */
/*--------------------------------------------------------------*/
#include "vex.h"
#include "RobotConfig.h"
using namespace vex;
brain Brain;

//Initializations from RobotConfig.h
//Motors
motor mtrLeft = motor(PORT1, false);
motor mtrRight = motor(PORT2, true);
motor mtrLeftFront = motor(PORT5, false);
motor mtrRightFront = motor(PORT3, true);
motor mtrArm = motor(PORT7, ratio36_1);
motor mtrIntakeLeft = motor(PORT8, ratio36_1, true);
motor mtrIntakeRight = motor(PORT9, ratio36_1, false);
motor mtrRampLift = motor(PORT4, true);

//Peripherals
light cubeBump = light(Brain.ThreeWirePort.A);
inertial navInert = inertial(PORT6);
controller ctrPrimary = controller(controllerType::primary);//Create the controller
//gyro gyroDrive = gyro(Brain.ThreeWirePort.H);

//extern variables
bool colorRed;
int autonMode;

void wait(int time){
    task::sleep(time);
}
