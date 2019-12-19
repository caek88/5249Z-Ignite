#include "RobotConfig.h"
int auton(){
    if (autonMode == 1){
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        deployRobot();
        originalLight = cubeBump.value(analogUnits::mV);
        maxSpeed = 35;
        driveToPos(24);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (distance < 18 && distance > 6){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        } 
        turnToAngle(-90);
        while (yawError() > 2.5){
            task::sleep(10);
        }
    }
    ctrPrimary.Screen.print("Done");
    return 0; 

}
