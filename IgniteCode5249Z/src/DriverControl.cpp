#include "RobotConfig.h"

double speedMod = 1.0;
bool kristen = false;
void toggleSpeed(){
  if (confirmDriver()){
      ctrPrimary.Screen.setCursor(1,1);
      ctrPrimary.Screen.clearLine(1);
      if(speedMod == 0.75){
        speedMod = 1.0;
        ctrPrimary.Screen.print("Maximum Overdrive");
        mtrLeft.setMaxTorque(90, percentUnits::pct);
        mtrRight.setMaxTorque(90, percentUnits::pct);
        mtrLeftFront.setMaxTorque(90, percentUnits::pct);
        mtrRightFront.setMaxTorque(90, percentUnits::pct);
      }
      else{
        speedMod = 0.75;
        ctrPrimary.Screen.print("Slow Man");
        mtrLeft.setMaxTorque(20, percentUnits::pct);
        mtrRight.setMaxTorque(20, percentUnits::pct);
        mtrLeftFront.setMaxTorque(20, percentUnits::pct);
        mtrRightFront.setMaxTorque(20, percentUnits::pct);
      }
  }
}

void toggleMode(){
  if (confirmDriver()){
      kristen = !kristen;
      ctrPrimary.Screen.setCursor(2,1);
      ctrPrimary.Screen.clearLine(2);
      if(kristen == true){
        
        ctrPrimary.Screen.print("Kristen");
      }
      else{ 
        ctrPrimary.Screen.print("Jimbo");
      }
  }
}

int driver(){
    bool rampUp = false;
    bool rampMacro = false;
    bool deployed = false;
    ctrPrimary.ButtonA.pressed(toggleSpeed);
    ctrPrimary.ButtonUp.pressed(toggleMode);
    toggleSpeed();
    ctrPrimary.Screen.setCursor(2,1);
    ctrPrimary.Screen.print("Jimbo");
    //deployRobot();
    while (true){
        if (!kristen){
            if (!deployed && ctrPrimary.ButtonLeft.pressing()){
                deployRobot();
                deployed = true;
            }
            //speaker.spin(directionType::rev, 100, percentUnits::pct);
            int y = ctrPrimary.Axis3.position(percentUnits::pct);//Get the position of the controller for forward and back
            int x = ctrPrimary.Axis4.position(percentUnits::pct);//Get the position of the controller for Right and Left
            mtrLeft.spin(directionType::fwd, speedMod * (y+x), percentUnits::pct);
            mtrRight.spin(directionType::fwd, speedMod * (y-x), percentUnits::pct);
            mtrLeftFront.spin(directionType::fwd, speedMod * (y+x), percentUnits::pct);
            mtrRightFront.spin(directionType::fwd, speedMod * (y-x), percentUnits::pct);
            int arm = ctrPrimary.Axis2.position(percentUnits::pct);
            if(abs(arm) > 10){
              mtrArm.spin(directionType::fwd, -arm, velocityUnits::pct);
              //mtrRampLift.spin(directionType::fwd, 0.1*arm, velocityUnits::pct);
            } else {
              mtrArm.stop(hold);
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
                    mtrRampLift.spin(directionType::fwd, 30, velocityUnits::pct);
                } else if (ctrPrimary.ButtonL2.pressing()){
                    mtrRampLift.spin(directionType::fwd, -30, velocityUnits::pct);
                } else if(abs(arm) > 10){
                    mtrRampLift.spin(directionType::fwd, 0.2 * arm, velocityUnits::pct);
                } else {
                    mtrRampLift.stop(brakeType::hold);
                }
            }
            
        } else {
            int y = ctrPrimary.Axis3.position(percentUnits::pct);//Get the position of the controller for forward and back
            int x = ctrPrimary.Axis4.position(percentUnits::pct)/2;//Get the position of the controller for Right and Left
            mtrLeft.spin(directionType::fwd, y+x, percentUnits::pct);
            mtrRight.spin(directionType::fwd, y-x, percentUnits::pct);
            mtrLeftFront.spin(directionType::fwd, y+x, percentUnits::pct);
            mtrRightFront.spin(directionType::fwd, y-x, percentUnits::pct);
            if (ctrPrimary.ButtonL2.pressing()){
                mtrArm.spin(directionType::fwd, 50, velocityUnits::pct);
            } else if (ctrPrimary.ButtonL1.pressing()){
                mtrArm.spin(directionType::fwd, -50, velocityUnits::pct);
            } else {
                mtrArm.spin(directionType::fwd, 0, velocityUnits::pct);
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
                mtrRampLift.spin(directionType::fwd, 30, velocityUnits::pct);
            } else if (ctrPrimary.ButtonB.pressing()){
                mtrRampLift.spin(directionType::fwd, -30, velocityUnits::pct);
            } else {
                mtrRampLift.spin(directionType::fwd, 0, velocityUnits::pct);
            }
        }
        task::sleep(10);
    }
    return 0;
}
