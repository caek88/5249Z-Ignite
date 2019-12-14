#include "RobotConfig.h"
const int DOWN = 10;
const int UP = 539;
void deployRobot(){
    mtrIntakeLeft.spin(directionType::fwd, 100, velocityUnits::pct);
    mtrIntakeRight.spin(directionType::fwd, 100, velocityUnits::pct);
    int time = 0;
    while (!liftRamp(true, 80, 100)){
        if (time < 1000){
            mtrArm.spin(directionType::fwd, -50, velocityUnits::pct);
        } else {
            mtrArm.stop(brakeType::hold);
        }
        time += 10;
        task::sleep(10);
    }
    //task::sleep(300);
    time = 0;
    while (!liftRamp(false, 80, 100)){
        if (time < 1000){
            mtrArm.spin(directionType::fwd, 50, velocityUnits::pct);
        } else {
            mtrArm.stop(brakeType::coast);
        }
        time += 10;
        task::sleep(10);
    }
}
bool liftRamp(bool moveUp, double slow, double fast){
    if (moveUp){
        double speed = (double)(UP - mtrRampLift.rotation(rotationUnits::deg))/(UP - DOWN)*fast + slow;
        if (mtrRampLift.rotation(rotationUnits::deg) >= UP){
            return true;
        } else {
            mtrRampLift.spin(directionType::fwd, speed, velocityUnits::pct);
            return false;
        }
    } else {
        double speed = (double)(mtrRampLift.rotation(rotationUnits::deg)- DOWN)/(UP - DOWN)*fast + slow;
        if (mtrRampLift.rotation(rotationUnits::deg) <= DOWN){
            return true;
        } else {
            mtrRampLift.spin(directionType::fwd, -speed, velocityUnits::pct);
            return false;
        }
    }
}
void stackTower(int rotOut, bool ejectDown){
        
        mtrIntakeLeft.spin(directionType::fwd, 30, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, 30, velocityUnits::pct);
        while (abs(cubeBump.value(analogUnits::mV) - originalLight) > 50){
            Brain.Screen.printAt(10, 210, true, "Line Tracker: %d", cubeBump.value(analogUnits::mV));
            task::sleep(10);
        }
        mtrIntakeLeft.startRotateFor(rotOut, degrees);
        mtrIntakeRight.rotateFor(rotOut, degrees);
        mtrIntakeLeft.stop();
        mtrIntakeRight.stop();
        int time = 0;
        while (!liftRamp(true)){
            if (time > 1000){
                mtrIntakeLeft.startRotateFor(180, degrees);
                mtrIntakeRight.startRotateFor(180, degrees);
                time = 0;
            } else {
                time += 10;
            }
            task::sleep(10);
        }
        if (ejectDown){
            mtrIntakeLeft.spin(directionType::fwd, 10, velocityUnits::pct);
            mtrIntakeRight.spin(directionType::fwd, 10, velocityUnits::pct);
        }
        task::sleep(500);
        time = 0;
        while (!liftRamp(false)){
            if (time > 500){
                mtrIntakeLeft.stop();
                mtrIntakeRight.stop();
            }
            time += 10;
            task::sleep(10);
        }
        mtrIntakeLeft.stop();
        mtrIntakeRight.stop();
}