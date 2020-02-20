/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.2.0                                            */
/*    File: RobotConfig.cpp                                     */
/*    Description: Instantiates extern objects in RobotConfig.h */
/*--------------------------------------------------------------*/
#include "vex.h"
#include "RobotConfig.h"
using namespace vex;
brain Brain;

//Initializations from RobotConfig.h
//Motors
motor mtrLeft = motor(PORT12, false);
motor mtrRight = motor(PORT19, true);
motor mtrLeftFront = motor(PORT11, false);
motor mtrRightFront = motor(PORT20, true);
motor mtrArm = motor(PORT2, ratio36_1);
motor mtrIntakeLeft = motor(PORT1, ratio36_1, true);
motor mtrIntakeRight = motor(PORT10, ratio36_1, false);
motor mtrRampLift = motor(PORT18, ratio36_1, true);

//Peripherals
light cubeBump = light(Brain.ThreeWirePort.F);
limit limArm = limit(Brain.ThreeWirePort.E);
limit limRamp = limit(Brain.ThreeWirePort.G);
limit limArmBottom = limit(Brain.ThreeWirePort.H);
inertial navInert = inertial(PORT13);
controller ctrPrimary = controller(controllerType::primary);//Create the controller
controller ctrPartner = controller(controllerType::partner);
//gyro gyroDrive = gyro(Brain.ThreeWirePort.H);

//extern variables
bool colorRed;
int autonMode;

void wait(int time){
    task::sleep(time);
}
