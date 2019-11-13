#include "RobotConfig.h"
const int DOWN = 0;
const int UP = 1440;
const int SPEED = 70;
const int SLOW_SPEED = 30;
void deployRobot(){
    mtrRampLift1.spin(directionType::fwd, SPEED, velocityUnits::pct);
    mtrRampLift2.spin(directionType::fwd, SPEED, velocityUnits::pct);
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
        if (mtrRampLift1.rotation(rotationUnits::deg) >= UP){
            return true;
        } else {
            mtrRampLift1.spin(directionType::fwd, double(UP - mtrRampLift1.rotation(rotationUnits::deg))/(UP-DOWN) * SPEED + SLOW_SPEED, velocityUnits::pct);
            mtrRampLift2.spin(directionType::fwd, double(UP - mtrRampLift1.rotation(rotationUnits::deg))/(UP-DOWN) * SPEED + SLOW_SPEED, velocityUnits::pct);
            return false;
        }
    } else {
        if (mtrRampLift1.rotation(rotationUnits::deg) <= DOWN){
            return true;
        } else {
            mtrRampLift1.spin(directionType::fwd, (DOWN - mtrRampLift1.rotation(rotationUnits::deg)) * SPEED + SLOW_SPEED, velocityUnits::pct);
            mtrRampLift2.spin(directionType::fwd, (DOWN - mtrRampLift1.rotation(rotationUnits::deg)) * SPEED + SLOW_SPEED, velocityUnits::pct);
            return false;
        }
    }
}