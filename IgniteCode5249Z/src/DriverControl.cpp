#include "RobotConfig.h"

double speedMod = 1.0;
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

int driver(){
    bool rampUp = false;
    bool rampMacro = false;
    bool deployed = false;
    ctrPrimary.ButtonA.pressed(toggleSpeed);
    toggleSpeed();
    ctrPrimary.Screen.setCursor(2,1);
    ctrPrimary.Screen.print("Jimbo");
    //deployRobot();
    while (true){
        Brain.Screen.setPenWidth(5);
        Brain.Screen.printAt(10, 210, true, "Line Tracker: %d", cubeBump.value(analogUnits::mV));
        if (!deployed && ctrPrimary.ButtonLeft.pressing()){
            deployRobot();
            deployed = true;
        }
        //speaker.spin(directionType::rev, 100, percentUnits::pct);
        int y = ctrPrimary.Axis3.position(percentUnits::pct);//Get the position of the controller for forward and back
        int x = ctrPrimary.Axis4.position(percentUnits::pct);//Get the position of the controller for Right and Left
        chassisLeft(speedMod * (y+x));
        chassisRight(speedMod * (y-x));
        int armSpeed = ctrPrimary.Axis2.position(percentUnits::pct);
        if(abs(armSpeed) > 10){
          arm(-armSpeed);
          //mtrRampLift.spin(directionType::fwd, 0.1*arm, velocityUnits::pct);
        } else {
          armStop(brakeType::hold);
        }
        if (ctrPrimary.ButtonR1.pressing()){
            intake(100);
        } else if (ctrPrimary.ButtonR2.pressing()){
            intake(-100);
        } else {
            intakeStop(brakeType::hold);
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
                rampLift(30);
            } else if (ctrPrimary.ButtonL2.pressing()){
                rampLift(-30);
            } else if(abs(armSpeed) > 10){
                rampLift(0.2 * armSpeed);
            } else {
                rampLiftStop(brakeType::hold);
            }
        }
        task::sleep(10);
    }
    return 0;
}
