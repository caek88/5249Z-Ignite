#include "RobotConfig.h"
const int DOWN = 10;
const int UP = 539;
const int SPEED_MAX = 80;
const int SLOW_SPEED = 20;
void deployRobot(){
    mtrIntakeLeft.spin(directionType::fwd, 100, velocityUnits::pct);
    mtrIntakeRight.spin(directionType::fwd, 100, velocityUnits::pct);
    int time = 0;
    while (!liftRamp(true)){
        if (time < 1000){
            mtrArm.spin(directionType::fwd, -50, velocityUnits::pct);
        } else {
            mtrArm.stop(brakeType::hold);
        }
        time += 10;
        task::sleep(10);
    }
    mtrIntakeLeft.stop();
    mtrIntakeRight.stop();
    time = 0;
    while (!liftRamp(false)){
        if (time < 1000){
            mtrArm.spin(directionType::fwd, 50, velocityUnits::pct);
        } else {
            mtrArm.stop(brakeType::coast);
        }
        time += 10;
        task::sleep(10);
    }
}
bool liftRamp(bool moveUp){
    if (moveUp){
        double speed = (double)(UP - mtrRampLift.rotation(rotationUnits::deg))/(UP - DOWN)*SPEED_MAX + SLOW_SPEED;
        if (mtrRampLift.rotation(rotationUnits::deg) >= UP){
            return true;
        } else {
            mtrRampLift.spin(directionType::fwd, speed, velocityUnits::pct);
            return false;
        }
    } else {
        double speed = (double)(mtrRampLift.rotation(rotationUnits::deg)- DOWN)/(UP - DOWN)*SPEED_MAX + SLOW_SPEED;
        if (mtrRampLift.rotation(rotationUnits::deg) <= DOWN){
            return true;
        } else {
            mtrRampLift.spin(directionType::fwd, -speed, velocityUnits::pct);
            return false;
        }
    }
}