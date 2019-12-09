#include "RobotConfig.h"

int auton(){
    //deployRobot();
    vex::task driveTask = task(drivePID);
    vex::task positionTask = vex::task(pos);
    driveToPos(24.0, 0.0, false, 0);
    task::sleep(1000);
    //turnToAngle(90);
    driveToPos(24.0, 12.0, false, 0);
    task::sleep(1000);
    driveToPos(12,12, false, 0);
    task::sleep(1000);
    driveToPos(12, 0, false, 0);
    ctrPrimary.Screen.print("Done");
    return 0;
}
