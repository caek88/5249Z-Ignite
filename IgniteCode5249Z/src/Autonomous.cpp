#include "RobotConfig.h"
int auton(){
    xPosition = 0;
    yPosition = 0;
    if (autonMode == 1){
        vex::task driveTask = task(drivePID);
        driveGyro.setRotation(0, degrees);
        int colorMod = colorRed?-1:1;
        deployRobot();
        originalLight = cubeBump.value(analogUnits::mV);
        maxSpeed = 35;
        driveToPos(24);
        while (driveDistance() > 0.5) {
            double distance = driveDistance();
            if (distance < 18 && distance > 6){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        } 
        while (!turnToAngle(90)){
            task::sleep(10);
        }
    }
    ctrPrimary.Screen.print("Done");
    return 0; 

}
