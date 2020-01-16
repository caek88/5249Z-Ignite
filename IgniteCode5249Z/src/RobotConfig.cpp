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
motor mtrLeft = motor(PORT15, false);
motor mtrRight = motor(PORT16, true);
motor mtrLeftFront = motor(PORT11, false);
motor mtrRightFront = motor(PORT20, true);
motor mtrArm = motor(PORT10, ratio36_1, true);
motor mtrIntakeLeft = motor(PORT2, ratio36_1, true);
motor mtrIntakeRight = motor(PORT6, ratio36_1, false);
motor mtrRampLift = motor(PORT4, false);

//Peripherals
light cubeBump = light(Brain.ThreeWirePort.G);
inertial navInert = inertial(PORT12);
controller ctrPrimary = controller(controllerType::primary);//Create the controller
//gyro gyroDrive = gyro(Brain.ThreeWirePort.H);

//extern variables
bool colorRed;
int autonMode;

void wait(int time){
    task::sleep(time);
}
