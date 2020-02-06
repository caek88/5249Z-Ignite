/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.0                                              */
/*    File: Autonomous.cpp                                      */
/*    Description: Contains all the autons for the competition  */
/*--------------------------------------------------------------*/
#include "NavMethods.h"
#include "RobotConfig.h"
#include "RobotMethods.h"

int auton() {
  /*---------------*/
  /*    Auton 1    */
  /*---------------*/
  if (autonMode == 1) {//Tries to get 8 cubes, cubes may cross the auton line - use in skills
    vex::task driveTask = task(drivePID);
    resetPosition();
    int colorMod = colorRed ? -1 : 1;
    intake(-100);
    setOriginalLight();
    maxSpeed = 40;
    
    intake(-100);
    wait(2000);
    // Move forward to get 3 cubes
    driveToPos(40);
    int time = 0;
    while (longitudeError() > 0.5) {
      time += 10;
      wait(10);
    }
    wait(100);

    // turn to get other cubes
    maxSpeed = 40;
    turnToAngle(colorMod * 36);
    while (fabs(yawError()) > 2.5) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
        intake(-100);
      }
      wait(10);
    }
    wait(200);

    // Move backwards to position robot
    maxSpeed = 100;
    driveToPos(colorRed ? 36 : -34);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(200);

    // Turn to orient robot
    turnToAngle(colorMod * 0);
    maxSpeed = 40;
    while (fabs(yawError()) > 2.5) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(400);

    // Move forward to get 4 cubes
    intake(-100);
    maxSpeed = colorRed ? 38 : 40;
    driveToPos(38);
    while (longitudeError() > 0.5) {
      wait(10);
    }
    wait(300);
    // task::sleep(500);
    // intakeStop();
    // turn around to score
    turnToAngle(colorRed ? 151 : -152);
    maxSpeed = 32;
    while (fabs(yawError()) > 2.5) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
        // intakeStop(coast);
      }
      wait(10);
    }
    // Move to the scoring zone
    wait(100);
    maxSpeed = 55; // 60

    driveToPos(35);
    while (longitudeError() > 0.5) {
      if (longitudeError() < 7) {
        maxSpeed = 15;
        intakeStop(coast);
      }
      if (31 - longitudeError() > 11) {
        liftRamp(true);
      }
      wait(10);
    }
    intakeStop(coast);
    while (!liftRamp(true)) {
      wait(10);
    }
    rampLiftStop();
    wait(500);
    // Stack and move back
    intake(100);
    maxSpeed = 15;
    driveToPos(-20);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    intakeStop();
  }
  /*---------------*/
  /*    Auton 2    */
  /*---------------*/
  if (autonMode == 2) { //7 cubes, cubes will not cross the line
    vex::task driveTask = task(drivePID);
    resetPosition();
    int colorMod = colorRed ? -1 : 1;
    setOriginalLight();
    
    // Move forward to get 4 cubes
    intake(-100);
    wait(400);
    intake(0);
    maxSpeed = 40;
    driveToPos(38);
    while (longitudeError() > 0.5) {
      if (38 - longitudeError() > 3){
        intake(-100);
      }
      wait(10);
    }
    wait(300);

    //Turn to get first cube;
    maxSpeed = 20;
    turnToAngle(colorMod*20);
    while (fabs(yawError()) > 1.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      task::sleep(10);
    }
    wait(300);

    //Drive forward to get 6th cube
    maxSpeed = 40;
    driveToPos(13);
    while (longitudeError() > 0.5) {
      wait(10);
    }
    wait(300);

    //Turn to get 7th cube
    maxSpeed = 20;
    turnToAngle(colorMod*-10);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    //Drive forward to get 7th cube
    maxSpeed = 40;
    driveToPos(5);
    while (longitudeError() > 0.5) {
      wait(10);
    }
    wait(500);

    //Drive backward
    driveToPos(colorRed?-10:-9);
    while (fabs(longitudeError()) > 0.5) {
      task::sleep(10);
    }
    wait(500);

    // turn around to score
    turnToAngle(colorRed?141:-145);
    maxSpeed = 32;
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(100);

    // Move to the scoring zone
    maxSpeed = 100;
    driveToPos(33);
    while (longitudeError() > 0.5) {
      if (longitudeError() < 9) {
        maxSpeed = 15;
        intakeStop(coast);
      }
      task::sleep(10);
    }
    intakeStop(coast);
    while (!liftRamp(true)) {
      task::sleep(10);
    }
    rampLiftStop();
    task::sleep(500);
    // Stack and move back
    intake(100);
    maxSpeed = 20;
    driveToPos(-20);
    while (fabs(longitudeError()) > 0.5) {
      task::sleep(10);
    }
    intakeStop();
  }
  /*---------------*/
  /*    Auton 3    */
  /*---------------*/
  if (autonMode == 3) {
    vex::task driveTask = task(drivePID);
    resetPosition();
    int colorMod = colorRed ? -1 : 1;
    setOriginalLight();
    maxSpeed = 30;
    // Move forward to get 4 cubes
    intake(-100);
    maxSpeed = colorRed ? 38 : 40;
    driveToPos(40);
    while (longitudeError() > 0.5) {
      task::sleep(10);
    }
    wait(200);
    //angle for 5th
    turnToAngle(colorRed ? -8 : 8);
    //maxSpeed = 32;
    while (fabs(yawError()) > 0.5) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 20;
      }
      task::sleep(10);
    }
    wait(100);
    //pick up 5th
    maxSpeed = colorRed ? 38 : 40;
    driveToPos(17);
    while (longitudeError() > 0.5) {
      task::sleep(10);
    }
    //move back
    maxSpeed = 50;
    driveToPos(-13.5);
    while (longitudeError() > 0.5) {
      task::sleep(10);
    }
    // angle for 6th cube
    turnToAngle(colorRed ? -20 : 20);
    maxSpeed = 32;
    while (fabs(yawError()) > 2.5) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
        // intakeStop(coast);
      }
      task::sleep(10);
    }
    // Move forward to get a cube
    intake(-100);
    maxSpeed = colorRed ? 40 : 40;
    driveToPos(15);
    while (longitudeError() > 0.5) {
      task::sleep(10);
    }
    wait(300);
    // go back
    intake(-100);
    maxSpeed = colorRed ? 40 : 40;
    driveToPos(-15);
    while (longitudeError() > 0.5) {
      task::sleep(10);
    }
    wait(300);
    // turn back

    // turn around to score
    turnToAngle(colorRed ? 146 : -148);
    maxSpeed = 32;
    while (fabs(yawError()) > 0.5) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
        // intakeStop(coast);
      }
      task::sleep(10);
    }
    // Move to the scoring zone
    task::sleep(100);
    maxSpeed = 55; // 60

    driveToPos(36);
    while (longitudeError() > 0.5) {
      if (longitudeError() < 7) {
        maxSpeed = 15;
        intakeStop(coast);
      }
      if (31 - longitudeError() > 11) {
        liftRamp(true);
      }
      task::sleep(10);
    }
    intakeStop(coast);
    while (!liftRamp(true)) {
      task::sleep(10);
    }
    rampLiftStop();
    task::sleep(500);
    // Stack and move back
    intake(100);
    maxSpeed = 20;
    driveToPos(-20);
    while (fabs(longitudeError()) > 0.5) {
      task::sleep(10);
    }
    intakeStop();
  }




  /*---------------*/
  /*    Auton 4    */
  /*---------------*/
  if (autonMode == 4) {
    vex::task driveTask = task(drivePID);
    resetPosition();
    int colorMod = colorRed ? -1 : 1;
    intake(-100);
    setOriginalLight();

    // Move forward to intake cube and deploy
    maxSpeed = 70;
    driveToPos(47);
    while (longitudeError() > 0.5) {
      if(longitudeError() < 10 && longitudeError() > 5){
        intakeStop(hold);
      }
      task::sleep(10);
    }
    // Outtake and move backwards to be in line with 4 high cubes
    intake(100);
    wait(500);
    intakeStop();
    // Turn to be in line with cubes
    turnToAngle(colorRed ? 90 : -90);
    maxSpeed = 32;
    while (fabs(yawError()) > 2.5) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      task::sleep(10);
    }
    wait(300);
    // Move forward slowly while raising arms
    maxSpeed = 40;
    arm(-100);
    driveToPos(10);
    while (longitudeError() > 0.5) {
      if(fabs(mtrArm.rotation(deg)) > 285.0 && fabs(mtrArm.rotation(deg)) < 380.0){
        arm(-50);
      }
      if(fabs(mtrArm.rotation(deg)) > 380){
        armStop(hold);
      }
      task::sleep(10);
    }
    // Bring arms down while also driving forward faster
  }

  /*---------------*/
  /*    Auton 5    */
  /*---------------*/
  if (autonMode == 5){ // One point basic auton
      vex::task driveTask = task(drivePID);
      resetPosition();
      intake(-100);
      setOriginalLight();
      maxSpeed = 40;

      wait(100);
      // Move forward to shove one cube really hard
      driveToPos(10);
      intake(-100);
      wait(200);
      int time = 0;
      while (longitudeError() > 0.5) {
        if (time > 500 && time < 1000) {
          intake(100);
        } else {
          intake(-100);
        }
        time += 10;
        task::sleep(10);
      }
      task::sleep(1000);
      intake(100);//Intake out and drive backwards; don't look at the cube, it doesn't want you
      driveToPos(-10);
  }
  ctrPrimary.Screen.print("Done");
  return 0;
}
