#include "RobotConfig.h"

int auton(){
    //deployRobot();
    vex::task driveTask = task(drivePID);
    vex::task positionTask = vex::task(pos);
    driveToPos(12.0, 0);
    task::sleep(1000);
    driveToPos(12.0, 12.0);
    task::sleep(1000);
    return 0;
}
