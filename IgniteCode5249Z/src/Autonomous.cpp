#include "RobotConfig.h"

int auton(){
    deployRobot();
    vex::task driveTask = task(drivePID);
    vex::task positionTask = vex::task(pos);
    maxSpeed = 20;
    mtrIntakeLeft.spin(directionType::fwd, -100, velocityUnits::pct);
    mtrIntakeRight.spin(directionType::fwd, -100, velocityUnits::pct);
    driveToPos(30.0, 0.0, false, false, 0);
    task::sleep(1000);
    mtrIntakeLeft.stop();
    mtrIntakeRight.stop();
    maxSpeed = 50;
    driveToPos(6, 0.0, true, false, 0);
    driveToPos(6, 24, false, false, 0);
    ctrPrimary.Screen.print("Done");
    return 0;
}
