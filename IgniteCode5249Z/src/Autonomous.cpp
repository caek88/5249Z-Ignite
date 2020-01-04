#include "RobotConfig.h"
int auton(){
    if (autonMode == 1){
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        //deployRobot();
        originalLight = cubeBump.value(analogUnits::mV);
        maxSpeed = 35;
        intake(-70);
        driveToPos(36);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (distance < 27 && distance > 9){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        } 
        turnToAngle(30);
        while (yawError() > 2.5){
            task::sleep(10);
        }

        driveToPos(15);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (distance < 11 && distance > 4){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        } 
        task::sleep(30);

        driveToPos(-10);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (fabs(distance) < 7 && fabs(distance) > 3){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }

        turnToAngle(40);
        while (yawError() > 2.5){
            task::sleep(10);
        } 

        driveToPos(15);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (distance < 11 && distance > 4){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }

        task::sleep(200);
        intakeStop(hold);

        turnToAngle(200);
        while (yawError() > 2.5){
            task::sleep(10);
        } 

        driveToPos(30);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (distance < 23 && distance > 8){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }

        //stackTower();

        intake(50);
        driveToPos(-20);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (fabs(distance) < 15 && fabs(distance) > 5){
                maxSpeed = 60;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }
    }
    if (autonMode == 2){
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        //deployRobot();
        originalLight = cubeBump.value(analogUnits::mV);
        maxSpeed = 35;
        stackTower();

        intake(50);
        driveToPos(-20);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (fabs(distance) < 15 && fabs(distance) > 5){
                maxSpeed = 60;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }
    }
    ctrPrimary.Screen.print("Done");
    return 0; 

}
