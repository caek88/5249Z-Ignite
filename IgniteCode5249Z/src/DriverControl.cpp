/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.2.0                                            */
/*    File: DriverControl.cpp                                   */
/*    Description: Driver Control code for competition          */
/*--------------------------------------------------------------*/
#include "RobotConfig.h"
#include "RobotMethods.h"
#include <cstdio>
bool speedMax = true;
double speedMod = 0.75;
void toggleSpeed(){
  if (confirmDriver()){
      ctrPrimary.Screen.setCursor(1,1);
      ctrPrimary.Screen.clearLine(1);
      if(!speedMax){
        speedMod = 1.0;
        speedMax = true;
        ctrPrimary.Screen.print("Maximum Overdrive");
        mtrLeft.setMaxTorque(90, percentUnits::pct);
        mtrRight.setMaxTorque(90, percentUnits::pct);
        mtrLeftFront.setMaxTorque(90, percentUnits::pct);
        mtrRightFront.setMaxTorque(90, percentUnits::pct);
      }
      else{
        speedMod = 0.75;
        speedMax = false;
        ctrPrimary.Screen.print("Slow Man");
        mtrLeft.setMaxTorque(90, percentUnits::pct);
        mtrRight.setMaxTorque(90, percentUnits::pct);
        mtrLeftFront.setMaxTorque(90, percentUnits::pct);
        mtrRightFront.setMaxTorque(90, percentUnits::pct);
      }
  }
}

int driver(){
    bool rampUp = false;
    bool rampMacro = false;
    bool armMacro = false;
    int armMacroPos = 0;
    //ctrPrimary.ButtonA.pressed(toggleSpeed);
    if (speedMax){
        toggleSpeed();
    }
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
        Brain.Screen.printAt(10, 210, true, "arm: %f", mtrArm.rotation(deg));
        //speaker.spin(directionType::rev, 100, percentUnits::pct);
        int y = ctrPrimary.Axis3.position(percentUnits::pct);//Get the position of the controller for forward and back
        int x = ctrPrimary.Axis1.position(percentUnits::pct) * 0.5;//Get the position of the controller for Right and Left
        if (abs(x) < 5){
            x = 0;
        }
        if (abs(y) < 5){
            y = 0;
        }
        chassisLeft(speedMod * y + x * (speedMax?1.0:0.5));
        chassisRight(speedMod * y - x * (speedMax?1.0:0.5));
        if (ctrPrimary.ButtonL1.pressing() || ctrPrimary.ButtonL2.pressing()){
            armMacro = false;
        }
        if (armMacro){
            if (liftArm(armMacroPos)){
                armMacro = false;
            }
        } else {
            if (ctrPrimary.ButtonL1.pressing() && !limArm.pressing()){
                arm(-100);
            } else if (ctrPrimary.ButtonL2.pressing() && !limArmBottom.pressing()){
                arm(100);
            } else {
                armStop(hold);
            }
        }
        if (ctrPrimary.ButtonR1.pressing()){
            intake(limArmBottom.pressing()?100:50);
        } else if (ctrPrimary.ButtonR2.pressing()){
            intake(limArmBottom.pressing()?-100:-50);
        } else if (!rampMacro && !ctrPrimary.ButtonDown.pressing() && !ctrPrimary.ButtonRight.pressing()){
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
        if (ctrPartner.ButtonR1.pressing()){
            armMacro = true;
            armMacroPos = 2;
        }
        if (ctrPartner.ButtonR2.pressing()){
            armMacro = true;
            armMacroPos = 1;
        }
        if (ctrPartner.ButtonB.pressing()){
            armMacro = true;
            armMacroPos = 0;
        }
        if (ctrPrimary.ButtonRight.pressing() || ctrPrimary.ButtonDown.pressing()){
            rampMacro = false;
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
            } else if ((ctrPrimary.ButtonL1.pressing() || (armMacro && armMacroPos != 0)) && !limArm.pressing() && (mtrRampLift.rotation(degrees) < 200)){
                rampLift(80);
            } else if ((ctrPrimary.ButtonL2.pressing() || (armMacro && armMacroPos == 0)) && !limArmBottom.pressing() && (mtrArm.rotation(degrees) > -200)){
                rampMacro = true;
                rampUp = false;
            } else {
                if (limRamp.pressing()){
                    rampLiftStop(coast);
                } else {
                    rampLiftStop(hold);
                }
                
            }
        }
        task::sleep(10);
    }
    return 0;
}
