/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.2.0                                            */
/*    File: RobotMethods.cpp                                    */
/*    Description: Defines functions in RobotMethods.h          */
/*--------------------------------------------------------------*/
#include "RobotConfig.h"
#include "RobotMethods.h"
#include "PID.h"
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
    return (cubeBump.value(analogUnits::mV) - originalLight) > 50;
}
void setOriginalLight(){
    originalLight = cubeBump.value(analogUnits::mV);
}
bool liftRamp(bool moveUp, double slow, double fast){
    if (moveUp){
        double moveSpeed = (double)(UP - mtrRampLift.rotation(degrees))/(UP - DOWN)*fast + slow;
        if (mtrRampLift.rotation(degrees) >= UP){
            return true;
        } else {
            rampLift(moveSpeed);
            return false;
        }
    } else {
        if (!limRamp.pressing()){
            rampLift(-fast);
            return false;
        }
        return true;
    }
}
PID armPID = PID(2,0,0,0.01);
bool liftArm(int pos){
    int positions[] = {0, -450, -600};
    armPID.setPoint = positions[pos];
    arm(armPID.calculatePID(mtrArm.rotation(degrees)));
    if (fabs(armPID.setPoint - mtrArm.rotation(degrees)) < 2){
        return true;
    }
    return false;
}