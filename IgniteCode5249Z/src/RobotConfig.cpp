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
motor mtrLeft = motor(PORT11, false);
motor mtrRight = motor(PORT15, true);
motor mtrLeftFront = motor(PORT12, false);
motor mtrRightFront = motor(PORT14, true);
motor mtrArm = motor(PORT16, ratio36_1);
motor mtrIntakeLeft = motor(PORT1, ratio36_1, true);
motor mtrIntakeRight = motor(PORT2, ratio36_1, false);
motor mtrRampLift = motor(PORT17, ratio36_1, true);

//Peripherals
light cubeBump = light(Brain.ThreeWirePort.G);
limit limArm = limit(Brain.ThreeWirePort.H);
limit limRamp = limit(Brain.ThreeWirePort.F);
limit limArmBottom = limit(Brain.ThreeWirePort.E);
inertial navInert = inertial(PORT13);
controller ctrPrimary = controller(controllerType::primary);//Create the controller
//gyro gyroDrive = gyro(Brain.ThreeWirePort.H);

//extern variables
bool colorRed;
int autonMode;

void wait(int time){
    task::sleep(time);
}
