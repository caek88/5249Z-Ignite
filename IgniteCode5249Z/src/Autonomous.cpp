#include "RobotConfig.h"
int auton(){
    if (autonMode == 1){
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        deployRobot();
        originalLight = cubeBump.value(analogUnits::mV);
        maxSpeed = 35;
        double error;
        do {
            error = fabs(longitudeError());
            if (error < 18.0){
                maxSpeed = 80;
            }
            if (error < 6){
                maxSpeed = 30;
            }
            task::sleep(10);
        } while (error > 0.2);
        turnToAngle(-90);
        while (fabs(yawError()) > 2){
            task::sleep(10);
        }
        turnToAngle(90);
        
    }
    ctrPrimary.Screen.print("Done");
    return 0; 

}
