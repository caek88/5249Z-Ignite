#include "RobotConfig.h"

int auton(){
    //deployRobot();
    int i = 1;
    while(true){
      if(i == 1){
        
        vex::task driveTask = task(drivePID);
        vex::task positionTask = vex::task(pos);
        driveToPos(12.0, 0);
      }
      i=2;
      task::sleep(1000);
    }
    return 0;
}
