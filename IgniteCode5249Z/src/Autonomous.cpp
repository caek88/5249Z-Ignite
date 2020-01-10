#include "RobotConfig.h"
int auton(){

    if (autonMode == 1){
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
            task::sleep(10);
        } 
        task::sleep(1000);
        intakeStop(hold);
        turnToAngle(colorMod*20);
        while (fabs(yawError()) > 2.5){
            if (fabs(yawError()) < 10){
                maxSpeed = 10;
            }
            task::sleep(10);
        }
        driveToPos(-27);
        
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
        turnToAngle(colorMod*-145);
        while (fabs(yawError()) > 2.5){
            if (fabs(yawError()) < 10){
                maxSpeed = 10;
            }
            task::sleep(10);
        }
        task::sleep(500);
        maxSpeed = 35;
        driveToPos(15);
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
    if (autonMode == 3){
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
        task::sleep(200);
        intakeStop(hold);
        turnToAngle(colorMod*30);
        while (fabs(yawError()) > 2.5){
            if (fabs(yawError()) < 10){
                maxSpeed = 10;
            }
            task::sleep(10);
        }
        task::sleep(500);
        driveToPos(-36);
        
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
        turnToAngle(colorMod*-10);
        while (fabs(yawError()) > 2.5){
            if (fabs(yawError()) < 10){
                maxSpeed = 10;
            }
            task::sleep(10);
        }
        task::sleep(200);
        maxSpeed = 35;
        intake(-100);
        maxSpeed = 30;
        driveToPos(33);
        while (longitudeError() > 0.5){
            task::sleep(10);
        }
        task::sleep(500);
        intakeStop(hold);
        maxSpeed = 35;
        driveToPos(-15);
        while (fabs(longitudeError()) > 0.5) {
            double distance = longitudeError();
            if (distance < 23 && distance > 8){
                maxSpeed = 80;
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }
        maxSpeed = 25;
        task::sleep(500);
        turnToAngle(colorMod*-135);
        while (fabs(yawError()) > 2.5){
            if (fabs(yawError()) < 10){
                maxSpeed = 10;
            }
            task::sleep(10);
        }
        task::sleep(200);
        maxSpeed = 35;
        driveToPos(18);
        while (fabs(longitudeError()) > 0.5) {
            task::sleep(10);
        }
        stackTower();

        intake(100);
        driveToPos(-26);
        while (fabs(longitudeError()) > 0.5 || !liftRamp(false)) {
            double distance = longitudeError();
            if (fabs(distance) < 15 && fabs(distance) > 5){
                maxSpeed = 60;
                intakeStop();
            } else {
                maxSpeed = 35;
            }
            task::sleep(10);
        }
        intakeStop();
        turnToAngle(0);
        while (fabs(yawError()) > 2.5){
            if (fabs(yawError()) < 10){
                maxSpeed = 10;
            }
            task::sleep(10);
        }
        intake(-100);
        driveToPos(16);
        while (fabs(longitudeError()) > 0.5 || cubesClear()) {
            double distance = longitudeError();
            if (fabs(distance) < 15 && fabs(distance) > 5){
                maxSpeed = 60;
            } else {
                maxSpeed = 35;
            }
            if (!cubesClear()){
                intakeStop();
            }
            task::sleep(10);
        }
        intakeStop();
        driveToPos(-2);
        arm(-50);
        while (mtrArm.rotation(degrees) > -560){
            task::sleep(10);
        }
        armStop(hold);
        intake(50);
        task::sleep(2000);
    }
    ctrPrimary.Screen.print("Done");
    return 0; 
}
