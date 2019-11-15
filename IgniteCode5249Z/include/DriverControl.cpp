#include "RobotConfig.h"
#include "RobotMethods.cpp"
int driver(){
    bool kristen = false;
    bool rampUp = false;
    bool rampMacro = false;
    //deployRobot();
    while (true){
        if (ctrPrimary.ButtonUp.pressing()){
            kristen = !kristen;
            while (ctrPrimary.ButtonUp.pressing()){
                task::sleep(10);
            }
        }
        if (!kristen){
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
            if (ctrPrimary.ButtonX.pressing()){
                rampMacro = true;
                rampUp = true;
            }
            if (ctrPrimary.ButtonB.pressing()){
                rampMacro = true;
                rampUp = false;
            }
            if (rampMacro){
                if (liftRamp(rampUp)){
                    rampMacro = false;
                }
            } else {
                if (ctrPrimary.ButtonL1.pressing()){
                    mtrRampLift1.spin(directionType::fwd, 30, velocityUnits::pct);
                    mtrRampLift2.spin(directionType::fwd, 30, velocityUnits::pct);
                } else if (ctrPrimary.ButtonL2.pressing()){
                    mtrRampLift1.spin(directionType::fwd, -30, velocityUnits::pct);
                    mtrRampLift2.spin(directionType::fwd, -30, velocityUnits::pct);
                } else {
                    mtrRampLift1.spin(directionType::fwd, 0, velocityUnits::pct);
                    mtrRampLift2.spin(directionType::fwd, 0, velocityUnits::pct);
                }
            }
            
        } else {
            int y = ctrPrimary.Axis3.position(percentUnits::pct);//Get the position of the controller for forward and back
            int x = ctrPrimary.Axis4.position(percentUnits::pct);//Get the position of the controller for Right and Left
            mtrLeft.spin(directionType::fwd, y+x, percentUnits::pct);
            mtrRight.spin(directionType::fwd, y-x, percentUnits::pct);
            if (ctrPrimary.ButtonL2.pressing()){
                mtrArmLeft.spin(directionType::fwd, 50, velocityUnits::pct);
                mtrArmRight.spin(directionType::fwd, 50, velocityUnits::pct);
            } else if (ctrPrimary.ButtonL1.pressing()){
                mtrArmLeft.spin(directionType::fwd, -50, velocityUnits::pct);
                mtrArmRight.spin(directionType::fwd, -50, velocityUnits::pct);
            } else {
                mtrArmLeft.spin(directionType::fwd, 0, velocityUnits::pct);
                mtrArmRight.spin(directionType::fwd, 0, velocityUnits::pct);
            }
            
            if (ctrPrimary.ButtonR2.pressing()){
                mtrIntakeLeft.spin(directionType::fwd, 50, velocityUnits::pct);
                mtrIntakeRight.spin(directionType::fwd, 50, velocityUnits::pct);
            } else if (ctrPrimary.ButtonR1.pressing()){
                mtrIntakeLeft.spin(directionType::fwd, -50, velocityUnits::pct);
                mtrIntakeRight.spin(directionType::fwd, -50, velocityUnits::pct);
            } else {
                mtrIntakeLeft.spin(directionType::fwd, 0, velocityUnits::pct);
                mtrIntakeRight.spin(directionType::fwd, 0, velocityUnits::pct);
            }
            if (ctrPrimary.ButtonX.pressing()){
                mtrRampLift1.spin(directionType::fwd, 30, velocityUnits::pct);
                mtrRampLift2.spin(directionType::fwd, 30, velocityUnits::pct);
            } else if (ctrPrimary.ButtonB.pressing()){
                mtrRampLift1.spin(directionType::fwd, -30, velocityUnits::pct);
                mtrRampLift2.spin(directionType::fwd, -30, velocityUnits::pct);
            } else {
                mtrRampLift1.spin(directionType::fwd, 0, velocityUnits::pct);
                mtrRampLift2.spin(directionType::fwd, 0, velocityUnits::pct);
            }
        }
        task::sleep(10);
    }
    return 0;
}