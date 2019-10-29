#include "RobotConfig.h"

int driver(){
    while (true){
        speaker.spin(directionType::rev, 100, percentUnits::pct);
        int y = ctrPrimary.Axis3.position(percentUnits::pct);//Get the position of the controller for forward and back
        int x = ctrPrimary.Axis4.position(percentUnits::pct);//Get the position of the controller for Right and Left
        mtrLeft.spin(directionType::fwd, y+x, percentUnits::pct);
        mtrRight.spin(directionType::fwd, y-x, percentUnits::pct);
        int arm = ctrPrimary.Axis2.position(percentUnits::pct);
        if(abs(arm) > 10){
          mtrArmLeft.spin(directionType::fwd, arm, velocityUnits::pct);
          mtrArmRight.spin(directionType::fwd, arm, velocityUnits::pct);
        } else {
          mtrArmLeft.stop(hold);
          mtrArmRight.stop(hold);
        }
        if (ctrPrimary.ButtonR1.pressing()){
            mtrIntakeLeft.spin(directionType::fwd, 50, velocityUnits::pct);
            mtrIntakeRight.spin(directionType::fwd, 50, velocityUnits::pct);
        } else if (ctrPrimary.ButtonR2.pressing()){
            mtrIntakeLeft.spin(directionType::fwd, -50, velocityUnits::pct);
            mtrIntakeRight.spin(directionType::fwd, -50, velocityUnits::pct);
        } else {
            mtrIntakeLeft.spin(directionType::fwd, 0, velocityUnits::pct);
            mtrIntakeRight.spin(directionType::fwd, 0, velocityUnits::pct);
        }
        if (ctrPrimary.ButtonL1.pressing()){
            mtrRampLift.spin(directionType::fwd, 30, velocityUnits::pct);
            mtrRampLift.spin(directionType::fwd, 30, velocityUnits::pct);
        } else if (ctrPrimary.ButtonL2.pressing()){
            mtrRampLift.spin(directionType::fwd, -30, velocityUnits::pct);
            mtrRampLift.spin(directionType::fwd, -30, velocityUnits::pct);
        } else {
            mtrRampLift.spin(directionType::fwd, 0, velocityUnits::pct);
            mtrRampLift.spin(directionType::fwd, 0, velocityUnits::pct);
        }
        task::sleep(10);
    }
    return 0;
}