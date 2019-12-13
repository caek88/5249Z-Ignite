#include "RobotConfig.h"
int auton(){
    xPosition = 0;
    yPosition = 0;
    if (autonMode == 1){
        driveGyro.setRotation(0, degrees);
        int colorMod = colorRed?-1:1;
        deployRobot();
        vex::task driveTask = task(drivePID);
        vex::task positionTask = vex::task(pos);
        maxSpeed = 35;
        mtrRampLift.stop(brakeType::coast);
        mtrArm.stop(brakeType::hold);
        mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
        driveToPos(33.0, colorMod*0.0, false);
        task::sleep(450);
        mtrIntakeLeft.stop(brakeType::hold);
        mtrIntakeRight.stop(brakeType::hold);
        maxSpeed = 45;
        task::sleep(100);
        driveToPos(6.0, colorMod*22.0, true);
        maxSpeed = 37;
        turnToAngle(5*colorMod);
        task::sleep(150);
        mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
        maxSpeed = 30;
        task::sleep(100);
        driveToPos(42.0, yPosition, false, false);
        task::sleep(200);
        mtrIntakeLeft.stop(brakeType::hold);
        mtrIntakeRight.stop(brakeType::hold);
        maxSpeed = 35;
        driveToPos(20.0, colorMod*20.0, true);
        driveToPos(12.0, colorMod*30.0, false, true, true, 3000);
        int time = 0;
        while (!liftRamp(true)){
            if (time < 500){
                mtrIntakeLeft.spin(directionType::fwd, 30, velocityUnits::pct);
                mtrIntakeRight.spin(directionType::fwd, 30, velocityUnits::pct);
            } else {
                mtrIntakeLeft.stop(brakeType::hold);
                mtrIntakeRight.stop(brakeType::hold);
            }
            time += 10;
            task::sleep(10);
        }
        mtrIntakeLeft.spin(directionType::fwd, 100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, 100, velocityUnits::pct);
        driveToPos(xPosition + 4.0, yPosition - colorMod*4.0, true);
    }
    if (autonMode == 2){
        driveGyro.setRotation(0, degrees);
        int colorMod = colorRed?-1:1;
        deployRobot();
        vex::task driveTask = task(drivePID);
        vex::task positionTask = vex::task(pos);
        maxSpeed = 35;
        mtrRampLift.stop(brakeType::coast);
        mtrArm.stop(brakeType::hold);
        mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
        driveToPos(33.0, colorMod*0.0, false);
        task::sleep(450);
        mtrIntakeLeft.stop(brakeType::hold);
        mtrIntakeRight.stop(brakeType::hold);
        maxSpeed = 55;
        driveToPos(18.0, colorMod*0.0, true);
        maxSpeed = 45;
        turnToAngle(colorMod*135);
        maxSpeed = 35;
        driveToPos(10.0, colorMod*8.0, false, false, true, 3000);
        mtrIntakeLeft.spin(directionType::fwd, 30, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, 30, velocityUnits::pct);
        task::sleep(1250);
        mtrIntakeLeft.stop();
        mtrIntakeRight.stop();
        while (!liftRamp(true)){
            task::sleep(10);
        }
        mtrIntakeLeft.spin(directionType::fwd, 70, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, 70, velocityUnits::pct);
        driveToPos(xPosition + 6.0, yPosition - colorMod*6.0, true, false);
        mtrIntakeLeft.stop();
        mtrIntakeRight.stop();
        while (!liftRamp(false)){
            task::sleep(10);
        }
    }
    ctrPrimary.Screen.print("Done");
    return 0; 

}
