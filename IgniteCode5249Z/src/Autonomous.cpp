#include "RobotConfig.h"

int auton(){
    deployRobot();
    task::sleep(100);
    mtrArm.spin(directionType::fwd, 50, velocityUnits::pct);
    vex::task driveTask = task(drivePID);
    vex::task positionTask = vex::task(pos);
    maxSpeed = 35;
    mtrArm.stop(brakeType::hold);
    mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
    mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
    driveToPos(33.0, 0.0, false, false, 0, true);
    task::sleep(450);
    mtrIntakeLeft.stop();
    mtrIntakeRight.stop();
    maxSpeed = 37;
    task::sleep(100);
    driveToPos(4.0, 22.0, true, false, 0, true);
    turnToAngle(0.0);
    task::sleep(150);
    mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
    mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
    maxSpeed = 35;
    driveToPos(42.0, yPosition, false, false, 0, false);
    maxSpeed = 45;
    task::sleep(200);
    mtrIntakeLeft.stop(brakeType::hold);
    mtrIntakeRight.stop(brakeType::hold);
    driveToPos(10.0, yPosition+2.0, true, false, 0, true);
    turnToAngle(95.0);

    ctrPrimary.Screen.print("Done");
    return 0; 
}
