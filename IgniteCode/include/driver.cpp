#include "RobotConfig.h"
int kristen = 0;

void changeKristen(){
  if(kristen == 0){
    kristen = 1;
  }
  else if(kristen == 1){
    kristen = 0;
  }
}

int driver(){
    
    ctrPrimary.ButtonDown.pressed(changeKristen);   
        
        while (true){
            if (kristen == 0){
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
            } else if(kristen == 1){
                int y = ctrPrimary.Axis3.position(percentUnits::pct);//Get the position of the controller for forward and back
                int x2 = ctrPrimary.Axis2.position(percentUnits::pct);
                int x = ctrPrimary.Axis1.position(percentUnits::pct);//Get the position of the controller for Right and Left
                mtrLeft.spin(directionType::fwd, (y+(x+x2)), percentUnits::pct);
                mtrRight.spin(directionType::fwd, (y-(x+x2)), percentUnits::pct);
                if (ctrPrimary.ButtonL1.pressing()){
                    mtrArmLeft.spin(directionType::fwd, 100, velocityUnits::pct);
                    mtrArmRight.spin(directionType::fwd, 100, velocityUnits::pct);
                } else if (ctrPrimary.ButtonL2.pressing()){
                    mtrArmLeft.spin(directionType::fwd, -100, velocityUnits::pct);
                    mtrArmRight.spin(directionType::fwd, -100, velocityUnits::pct);
                } else {
                    mtrArmLeft.spin(directionType::fwd, 0, velocityUnits::pct);
                    mtrArmRight.spin(directionType::fwd, 0, velocityUnits::pct);
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
                    mtrRampLift.spin(directionType::fwd, 50, velocityUnits::pct);
                    mtrRampLift.spin(directionType::fwd, 50, velocityUnits::pct);
                } else if (ctrPrimary.ButtonB.pressing()){
                    mtrRampLift.spin(directionType::fwd, -50, velocityUnits::pct);
                    mtrRampLift.spin(directionType::fwd, -50, velocityUnits::pct);
                } else {
                    mtrRampLift.spin(directionType::fwd, 0, velocityUnits::pct);
                    mtrRampLift.spin(directionType::fwd, 0, velocityUnits::pct);
                }
                task::sleep(10);
            }

        }
    
    return 0;
}