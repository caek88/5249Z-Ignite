/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.0                                              */
/*    File: DriverControl.cpp                                   */
/*    Description: Driver Control code for competition          */
/*--------------------------------------------------------------*/
#include "RobotConfig.h"
#include "RobotMethods.h"
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
        mtrLeft.setMaxTorque(40, percentUnits::pct);
        mtrRight.setMaxTorque(40, percentUnits::pct);
        mtrLeftFront.setMaxTorque(40, percentUnits::pct);
        mtrRightFront.setMaxTorque(40, percentUnits::pct);
      }
  }
}

int driver(){
    bool rampUp = false;
    bool rampMacro = false;
    bool deployed = false;
    //ctrPrimary.ButtonA.pressed(toggleSpeed);
    toggleSpeed();
    ctrPrimary.Screen.setCursor(2,1);
    ctrPrimary.Screen.print("Jimbo");
    setOriginalLight();
    //deployRobot();
    bool waitForReleaseA = false;
    while (true){
        if (!waitForReleaseA && ctrPrimary.ButtonA.pressing()){
            toggleSpeed();
            waitForReleaseA = true;
        }
        if (waitForReleaseA && !ctrPrimary.ButtonA.pressing()){
            waitForReleaseA = false;
        }
        Brain.Screen.setPenWidth(5);
        Brain.Screen.printAt(10, 210, true, "Line Tracker: %d", cubeBump.value(analogUnits::mV));
        if (!deployed && ctrPrimary.ButtonLeft.pressing()){
            deployRobot();
            deployed = true;
        }
        //speaker.spin(directionType::rev, 100, percentUnits::pct);
        int y = ctrPrimary.Axis3.position(percentUnits::pct);//Get the position of the controller for forward and back
        int x = ctrPrimary.Axis1.position(percentUnits::pct);//Get the position of the controller for Right and Left
        chassisLeft(speedMod * (y+x));
        chassisRight(speedMod * (y-x));
        if (ctrPrimary.ButtonL1.pressing()){
            arm(-100);
        } else if (ctrPrimary.ButtonL2.pressing()){
            arm(100);
        } else {
            armStop(hold);
        }
        if (ctrPrimary.ButtonR1.pressing()){
            intake(100);
        } else if (ctrPrimary.ButtonR2.pressing()){
            intake(-100);
        } else if (!rampMacro && !ctrPrimary.ButtonL1.pressing() && !ctrPrimary.ButtonL2.pressing()){
            intakeStop(brakeType::hold);
        } else {
            intakeStop(brakeType::coast);
        }
        if (ctrPrimary.ButtonY.pressing()){
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
            if (ctrPrimary.ButtonRight.pressing()){
                rampLift(100);
            } else if (ctrPrimary.ButtonDown.pressing()){
                rampLift(-100);
            } else if (ctrPrimary.ButtonL1.pressing()){
                rampLift(40);
            } else if (ctrPrimary.ButtonL2.pressing()){
                rampLift(-40);
            } else {
                rampLiftStop();
            }
        }
        task::sleep(10);
    }
    return 0;
}
