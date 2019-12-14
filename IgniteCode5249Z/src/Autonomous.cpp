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
        driveToPos(6.0, colorMod*22.0, true);
        maxSpeed = 37;
        turnToAngle(5*colorMod);
        task::sleep(150);
        mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
        maxSpeed = 30;
        task::sleep(100);
        driveToPos(42.0, yPosition, false, false);
        stackTower(700);
        mtrIntakeLeft.spin(directionType::fwd, 25, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, 25, velocityUnits::pct);
        maxSpeed = 20;
        leftPosition -= 360;
        rightPosition -= 360;
        task::sleep(2000);
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
        task::sleep(750);
        mtrIntakeLeft.stop(brakeType::hold);
        mtrIntakeRight.stop(brakeType::hold);
        maxSpeed = 55;
        driveToPos(18.0, colorMod*0.0, true);
        maxSpeed = 45;
        turnToAngle(colorMod*135);
        maxSpeed = 35;
        driveToPos(xPosition - 9, yPosition + colorMod*9.0, false, false, true, 3000);
        stackTower(colorRed?270:300);
        mtrIntakeLeft.spin(directionType::fwd, 30, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, 30, velocityUnits::pct);
        maxSpeed = 20;
        leftPosition -= 360;
        rightPosition -= 360;
        task::sleep(2000);
        maxSpeed = 40;
        driveToPos(24, -9*colorMod, true);
        mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
        turnToAngle(0);
        driveToPos(46, -9*colorMod, false, false);
        while (!cubeBump.pressing()){
            task::sleep(10);
        }
        task::sleep(250);
        mtrIntakeLeft.stop(brakeType::hold);
        mtrIntakeRight.stop(brakeType::hold);
        mtrRampLift.startRotateTo(100, rotationUnits::deg);
        mtrArm.rotateTo(-600, rotationUnits::deg);
        mtrIntakeLeft.spin(directionType::fwd, 100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    if (autonMode == 3){
        mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
        vex::task driveTask = task(drivePID);
        vex::task positionTask = vex::task(pos);
        while (!cubeBump.pressing()){
            task::sleep(10);
        }
        task::sleep(250);
        mtrIntakeLeft.stop(brakeType::hold);
        mtrIntakeRight.stop(brakeType::hold);
        mtrRampLift.startRotateTo(100, rotationUnits::deg);
        mtrArm.rotateTo(-600, rotationUnits::deg);
        mtrIntakeLeft.spin(directionType::fwd, 100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, 100, velocityUnits::pct);
    }
    ctrPrimary.Screen.print("Done");
    return 0; 

}
