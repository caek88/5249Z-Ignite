#include "RobotConfig.h"
int auton(){
    xPosition = 0;
    yPosition = 0;
    if (autonMode == 1){
        bool colorMod = colorRed?-1:1;
        deployRobot();
        task::sleep(100);
        mtrArm.spin(directionType::fwd, 50, velocityUnits::pct);
        vex::task driveTask = task(drivePID);
        vex::task positionTask = vex::task(pos);
        maxSpeed = 35;
        mtrArm.stop(brakeType::hold);
        mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
        driveToPos(33.0, colorMod*0.0, false);
        task::sleep(450);
        mtrIntakeLeft.stop();
        mtrIntakeRight.stop();
        maxSpeed = 37;
        task::sleep(100);
        driveToPos(4.0, colorMod*22.0, true);
        turnToAngle(0.0);
        task::sleep(150);
        mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
        mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
        maxSpeed = 35;
        driveToPos(42.0, yPosition, false, false);
        maxSpeed = 45;
        task::sleep(200);
        mtrIntakeLeft.stop(brakeType::hold);
        mtrIntakeRight.stop(brakeType::hold);
        driveToPos(10.0, yPosition+colorMod*2.0, true);
        turnToAngle(colorMod*95.0);
    }
    if (autonMode == 2){
        deployRobot();
        task::sleep(100);
        mtrArm.spin(directionType::fwd, 50, velocityUnits::pct);
        vex::task driveTask = task(drivePID);
        vex::task positionTask = vex::task(pos);
        maxSpeed = 35;
        mtrArm.stop(brakeType::hold);
    }
    ctrPrimary.Screen.print("Done");
    return 0; 

}
