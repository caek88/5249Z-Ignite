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
    }
    if (autonMode == 2){
        vex::task driveTask = task(drivePID);
        driveGyro.setRotation(0, degrees);
        int colorMod = colorRed?-1:1;
        deployRobot();
        originalLight = cubeBump.value(analogUnits::mV);
        maxSpeed = 35;
    }
    ctrPrimary.Screen.print("Done");
    return 0; 

}
