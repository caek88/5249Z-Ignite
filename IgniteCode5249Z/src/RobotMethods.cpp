#include "RobotConfig.h"
const int DOWN = 10;
const int UP = 539;
const int SPEED_MAX = 80;
const int SLOW_SPEED = 20;
void deployRobot(){
    mtrRampLift1.spin(directionType::fwd, SPEED_MAX, velocityUnits::pct);
    mtrRampLift2.spin(directionType::fwd, SPEED_MAX, velocityUnits::pct);
    while (mtrRampLift1.rotation(rotationUnits::deg) < UP){
        task::sleep(10);
    }
    mtrRampLift1.stop(brakeType::coast);
    mtrRampLift2.stop(brakeType::coast);
    mtrArmLeft.spin(directionType::fwd, SLOW_SPEED, velocityUnits::pct);
    mtrArmRight.spin(directionType::fwd, SLOW_SPEED, velocityUnits::pct);
    task::sleep(500);
    mtrArmLeft.stop(brakeType::coast);
    mtrArmRight.stop(brakeType::coast);
}
bool liftRamp(bool moveUp){
    if (moveUp){
        double speed = (double)(UP - mtrRampLift1.rotation(rotationUnits::deg))/(UP - DOWN)*SPEED_MAX + SLOW_SPEED;
        if (mtrRampLift1.rotation(rotationUnits::deg) >= UP){
            return true;
        } else {
            mtrRampLift1.spin(directionType::fwd, speed, velocityUnits::pct);
            mtrRampLift2.spin(directionType::fwd, speed, velocityUnits::pct);
            return false;
        }
    } else {
        double speed = (double)(mtrRampLift1.rotation(rotationUnits::deg)- DOWN)/(UP - DOWN)*SPEED_MAX + SLOW_SPEED;
        if (mtrRampLift1.rotation(rotationUnits::deg) <= DOWN){
            return true;
        } else {
            mtrRampLift1.spin(directionType::fwd, -speed, velocityUnits::pct);
            mtrRampLift2.spin(directionType::fwd, -speed, velocityUnits::pct);
            return false;
        }
    }
}