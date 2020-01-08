#include "RobotConfig.h"
int auton(){
    if (autonMode == 1){
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        deployRobot();
        originalLight = cubeBump.value(analogUnits::mV);
        maxSpeed = 40;
        //drive forward and pick up cubes
        intake(-100);
        driveToPos(36);
        while (longitudeError() > 0.5) {
            task::sleep(10);
        } 
        task::sleep(500);
        intakeStop(hold);
        turnToAngle(colorMod*20);
        while (fabs(yawError()) > 2.5){
            if (fabs(yawError()) < 10){
                maxSpeed = 10;
            }
            task::sleep(10);
        }
        task::sleep(500);
        maxSpeed = 35;
        driveToPos(13);
        while (longitudeError() > 0.5) {
            if(longitudeError() < 5){
                intake(-50);
            }
            task::sleep(10);
        } 
        task::sleep(1000);
        turnToAngle(0);
        while (fabs(yawError()) > 2.5){
            if (fabs(yawError()) < 10){
                maxSpeed = 10;
            }
            task::sleep(10);
        }
        driveToPos(-30);
        intakeStop(hold);
        while (fabs(longitudeError()) > 0.5) {
            double distance = fabs(longitudeError());
            if (distance > 6 && distance < 34){
                maxSpeed = 70;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }
        task::sleep(200);
        turnToAngle(colorMod*-135);
        while (fabs(yawError()) > 2.5){
            if (fabs(yawError()) < 10){
                maxSpeed = 10;
            }
            task::sleep(10);
        }
        task::sleep(500);
        maxSpeed = 35;
        driveToPos(11);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (distance < 23 && distance > 8){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }

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
    if (autonMode == 2){
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        deployRobot();
        originalLight = cubeBump.value(analogUnits::mV);
        maxSpeed = 30;
        //drive forward and pick up cubes
        intake(-100);
        driveToPos(38);
        while (longitudeError() > 0.5) {
            task::sleep(10);
        } 
        task::sleep(500);
        driveToPos(-16);
        intakeStop(hold);
        while (fabs(longitudeError()) > 0.5) {
            double distance = fabs(longitudeError());
            if (distance > 6 && distance < 34){
                maxSpeed = 70;
                intakeStop(hold);
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }
        task::sleep(200);
        turnToAngle(colorMod*-135);
        while (fabs(yawError()) > 2.5){
            if (fabs(yawError()) < 10){
                maxSpeed = 10;
            }
            task::sleep(10);
        }
        task::sleep(500);
        maxSpeed = 35;
        driveToPos(14);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (distance < 23 && distance > 8){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }

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
