/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.0                                              */
/*    File: Autonomous.cpp                                      */
/*    Description: Contains all the autons for the competition  */
/*--------------------------------------------------------------*/
#include "RobotConfig.h"
#include "RobotMethods.h"
#include "NavMethods.h"
int auton(){
    
    if (autonMode == 1){

      vex::task driveTask = task(drivePID);
      resetPosition();
      int colorMod = colorRed?-1:1;
      intake(-100);
      setOriginalLight();
      maxSpeed = 40;
      intake(-100);
      //Move forward to get 3 cubes
      driveToPos(43);
      int time = 0;
      while (longitudeError() > 0.5) {
        if (time > 500 && time < 1000){
            intake(100);
        } else {
            intake(-100);
        }
        time += 10;
        task::sleep(10);
      } 
      task::sleep(550);
      intakeStop();
      //turn to get other cubes
      maxSpeed = 40;
      turnToAngle(colorMod*30);
      while (fabs(yawError()) > 2.5){
        if (fabs(yawError()) < 10){
          maxSpeed = 10;
        }
        task::sleep(10);
      }
      task::sleep(200);
      //Move backwards to position robot
      maxSpeed = 100;//70
      driveToPos(-40);//45
      while (fabs(longitudeError()) > 0.5) {
        //maxSpeed = 70;
        task::sleep(10);
      } 
      //task::sleep(200);
      //Turn to orient robot
      turnToAngle(colorMod*0);
      maxSpeed = 40;
      while (fabs(yawError()) > 2.5){
        if (fabs(yawError()) < 10){
          maxSpeed = 10;
        }
        task::sleep(10);
      }
      //task::sleep(400);
      //Move forward to get 4 cubes
      intake(-100);
      maxSpeed = 30;
      driveToPos(35);
      while (longitudeError() > 0.5) {
        task::sleep(10);
      } 
      //task::sleep(500);
      //intakeStop();
      //turn around to score
      turnToAngle(colorMod*-152);
      maxSpeed = 32;
      while (fabs(yawError()) > 2.5){
        if (fabs(yawError()) < 10){
          maxSpeed = 10;
          intakeStop(coast);
        }
        task::sleep(10);
      }
      //Move to the scoring zone
      task::sleep(200);
      maxSpeed = 55;//60
      
      driveToPos(31);
      while (longitudeError() > 0.5) {
        if (longitudeError() < 7){
          maxSpeed = 15;
          intakeStop(coast);
        }
        if (31-longitudeError() > 10){
          liftRamp(true);
        }
        task::sleep(10);
      } 
      while (!longitudeError()){
        task::sleep(10);
      }
      task::sleep(1000);
      //Stack and move back
      intake(50);
      maxSpeed = 15;
      driveToPos(-20);
      while (longitudeError() > 0.5) {
        task::sleep(10);
      } 
      /*
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        deployRobot();
        setOriginalLight();
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
        }*/
    }








    if (autonMode == 2){
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        //deployRobot();
        setOriginalLight();
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
        intakeStop(coast);
        while(!liftRamp(true)){
          task::sleep(10);
        }
        task::sleep(500);
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
        intakeStop();
        while (!liftRamp(false));
    }





    if (autonMode == 3){
        vex::task driveTask = task(drivePID);
        resetPosition();
        int colorMod = colorRed?-1:1;
        deployRobot();
        setOriginalLight();
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
        intake(-100);
        maxSpeed = 35;
        driveToPos(17);
        while (fabs(longitudeError()) > 0.5) {
            task::sleep(10);
        }
        stackTower();

        intake(100);
        driveToPos(-22);
        while (!liftRamp(false) || fabs(longitudeError()) > 0.5 ) {//Special short curcuit if switched
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
        arm(-50);
        task::sleep(500);
        arm(50);
        task::sleep(500);
        armStop();
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
