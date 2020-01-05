#include "RobotConfig.h"
int auton(){
    if (autonMode == 1){
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        //deployRobot();
        originalLight = cubeBump.value(analogUnits::mV);
        maxSpeed = 40;
        //drive forward and pick up cubes
        intake(-70);
        driveToPos(36);
        while (longitudeError() > 0.5) {
            task::sleep(10);
        } 
        task::sleep(500);
        intakeStop(hold);
        turnToAngle(20);
        while (yawError() > 2.5){
            task::sleep(10);
        }
        task::sleep(500);
        maxSpeed = 35;
        driveToPos(12);
        while (longitudeError() > 0.5) {
            if(longitudeError() < 2){
                intake(-30);
            }
            task::sleep(10);
        } 
        task::sleep(1500);
        driveToPos(-10);
        while (longitudeError() > 0.5) {
            if (cubesClear()){
                intakeStop(hold);
            }
            double distance = longitudeError();
            task::sleep(10);
        }
        task::sleep(200);
        turnToAngle(30);
        while (yawError() > 2.5){
            if (cubesClear()){
                intakeStop(hold);
            }
            task::sleep(10);
        }
        task::sleep(500);
        maxSpeed = 35;
        driveToPos(15);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (distance < 11 && distance > 4){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            if (distance < 6){
                intake(-30);
            }
            task::sleep(10);
        }
        task::sleep(500);
        intakeStop(hold);
        /*driveToPos(-30);
        while (longitudeError() > 0.5) {
            double distance = longitudeError();
            if (distance < 11 && distance > 4){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }
        task::sleep(500);
        
        turnToAngle(220);
        while (fabs(yawError()) > 2.5){
            task::sleep(10);
        } 
        task::sleep(500);
        maxSpeed = 35;
        driveToPos(20);
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
        }*/
    }
    if (autonMode == 2){
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        //deployRobot();
        originalLight = cubeBump.value(analogUnits::mV);
        maxSpeed = 35;
        turnToAngle(90);
        /*stackTower();

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
        }*/
    }
    ctrPrimary.Screen.print("Done");
    return 0; 
}
