/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.0                                              */
/*    File: RobotMethods.cpp                                    */
/*    Description: Defines functions in RobotMethods.h          */
/*--------------------------------------------------------------*/
#include "RobotConfig.h"
#include "RobotMethods.h"
const int DOWN = 10;
const int UP = 1290;//539
int originalLight = 0;
void intake(double speed){
    mtrIntakeLeft.spin(directionType::fwd, speed, velocityUnits::pct);
    mtrIntakeRight.spin(directionType::fwd, speed, velocityUnits::pct);
}
void intakeStop(brakeType stopMode){
    mtrIntakeLeft.stop(stopMode);
    mtrIntakeRight.stop(stopMode);
}
void chassisLeft(double speed){
    mtrLeft.spin(directionType::fwd, speed, velocityUnits::pct);
    mtrLeftFront.spin(directionType::fwd, speed, velocityUnits::pct);
}
void chassisRight(double speed){
    mtrRight.spin(directionType::fwd, speed, velocityUnits::pct);
    mtrRightFront.spin(directionType::fwd, speed, velocityUnits::pct);
}
void arm(double speed){
    mtrArm.spin(directionType::fwd, speed, velocityUnits::pct);
}
void armStop(brakeType stopMode){
    mtrArm.stop(stopMode);
}
void rampLift(double speed){
    mtrRampLift.spin(directionType::fwd, speed, velocityUnits::pct);
}
void rampLiftStop(brakeType stopMode){
    mtrRampLift.stop(stopMode);
}
bool cubesClear(){
    return abs(cubeBump.value(analogUnits::mV) - originalLight) < 50;
}
void setOriginalLight(){
    originalLight = cubeBump.value(analogUnits::mV);
}
void deployRobot(){
    intake(100);
    int time = 0;
    while (!liftRamp(true, 80, 100)){
        if (time < 1000){
            arm(-50);
        } else {
            armStop(brakeType::hold);
        }
        time += 10;
        task::sleep(10);
    }
    //task::sleep(300);
    time = 0;
    while (!liftRamp(false, 80, 100)){
        if (time < 2000 && time > 1000){
            arm(100);
        } else {
            armStop(brakeType::hold);
        }
        time += 10;
        task::sleep(10);
    }
    rampLiftStop();
}
bool liftRamp(bool moveUp, double slow, double fast, bool outtake){
    if (moveUp){
        if (outtake){
            if (!cubesClear()){
                intakeStop();
            } else {
                intake(20);
            }
        }
        double moveSpeed = (double)(UP - mtrRampLift.rotation(degrees))/(UP - DOWN)*fast + slow;
        if (mtrRampLift.rotation(degrees) >= UP){
            return true;
        } else {
            rampLift(moveSpeed);
            return false;
        }
    } else {
        double moveSpeed = (double)(mtrRampLift.rotation(degrees)- DOWN)/(UP - DOWN)*fast + slow;
        if (mtrRampLift.rotation(degrees) <= DOWN){
            return true;
        } else {
            rampLift(-moveSpeed);
            return false;
        }
    }
}
void stackTower(bool waitForCube){
        intake(30);
        while (waitForCube && cubesClear()){
            Brain.Screen.printAt(10, 210, true, "Line Tracker: %d", cubeBump.value(analogUnits::mV));
            task::sleep(10);
            if(ctrPrimary.ButtonB.pressing()){
              return;
            }
        }
        intakeStop();
        int time = 0;
        while (!liftRamp(true, 15,50,true)){
            if (time > 1000){
                mtrIntakeLeft.startRotateFor(180, degrees);
                mtrIntakeRight.startRotateFor(180, degrees);
                time = 0;
            } else {
                time += 10;
            }
            task::sleep(10);
            if(ctrPrimary.ButtonB.pressing()){
              return;
            }
        }
        arm(50);
        task::sleep(500);
        armStop();
        intakeStop();
}
