/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.2.0                                            */
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
  if (autonMode == 1) { // Tries to get 8 cubes, cubes may cross the auton line
                        // - use in skills
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
  // 6 point game auton
  if (autonMode == 2) {
    vex::task driveTask = task(drivePID);
    resetPosition();
    int colorMod = colorRed ? -1 : 1;
    setOriginalLight();

    // Move forward to get 4 cubes
    intake(-100);
    wait(400);
    intake(0);
    maxSpeed = 40;
    driveToPos(40);
    while (longitudeError() > 0.5) {
      if (38 - longitudeError() > 3) {
        intake(-100);
      }
      wait(10);
    }
    wait(300);

    // Angle for last cube
    maxSpeed = 20;
    turnToAngle(colorMod * 20);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    // Pick up cube
    maxSpeed = 40;
    driveToPos(13);
    intake(-100);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);

    // Move back
    maxSpeed = 40;
    driveToPos(-13);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);
    intakeStop();


    //turn to score
    maxSpeed = 30;
    turnToAngle(colorMod * -150);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    maxSpeed = 40;
    driveToPos(30);
    while (longitudeError() > 0.5) {
      if (longitudeError() < 7) {
        maxSpeed = 15;
        intakeStop(coast);
      }
      if (30 - longitudeError() > 6) {
        liftRamp(true);
      }
      wait(10);
    }
    intakeStop(coast);
    while (!liftRamp(true)) {
      wait(10);
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
  if (autonMode == 3) {//5 point game auton
    vex::task driveTask = task(drivePID);
    resetPosition();
    int colorMod = colorRed ? -1 : 1;
    setOriginalLight();

    // Move forward to get 4 cubes
    intake(-100);
    wait(400);
    intake(0);
    maxSpeed = 40;
    driveToPos(40);
    while (longitudeError() > 0.5) {
      if (38 - longitudeError() > 3) {
        intake(-100);
      }
      wait(10);
    }
    wait(300);

    // Move backward to scoring zone
    driveToPos(-15);
    while (fabs(longitudeError()) > 0.5) {
      if (38 - longitudeError() > 3) {
        intake(-100);
      }
      wait(10);
    }
    wait(1000);

    // Turn to zone
    maxSpeed = 30;
    turnToAngle(colorMod * -135);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(700);

    maxSpeed = 40;
    driveToPos(16);
    while (longitudeError() > 0.5) {
      if (longitudeError() < 10) {
        maxSpeed = 15;
        intakeStop(coast);
      }
      task::sleep(10);
    }
    int time = 0;
    while (cubesClear() && time < 700) {
      intake(50);
      time += 10;
      wait(10);
    }
    intakeStop();
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
  if (autonMode == 4) { // One point basic auton
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
    intake(100); // Intake out and drive backwards; don't look at the cube, it
                 // doesn't want you
    driveToPos(-10);
  }
  /*---------------*/
  /*    Auton 5    */
  /*---------------*/
  //4 cubes in unprotected
  if (autonMode == 5) {
    vex::task driveTask = task(drivePID);
    resetPosition();
    int colorMod = colorRed ? -1 : 1;
    setOriginalLight();

    // Move forward to get cube
    intake(-100);
    wait(300);
    intake(0);
    wait(1000);
    maxSpeed = 40;
    driveToPos(20);
    while (longitudeError() > 0.5) {
      if (19 - longitudeError() > 3) {
        intake(-100);
      }
      wait(10);
    }
    wait(500);
    intake(-100);
    // Turn to tower
    maxSpeed = 30;
    turnToAngle(colorMod * -90);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);
    intake(-100);
    // Move forward to get cube 2
    maxSpeed = 40;
    driveToPos(14);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);
    intake(-100);
    //Move backwards
    driveToPos(-15);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);

    //turn around
    maxSpeed = 30;
    turnToAngle(colorMod * 90);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    //Drive forward for last cube
    maxSpeed = 40;
    driveToPos(20);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);

    //Turn to score
    maxSpeed = 30;
    turnToAngle(colorMod * 135);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    
    intakeStop();
    maxSpeed = 15;
    driveToPos(4);
    while (longitudeError() > 0.5) {
      task::sleep(10);
    }
    int time = 0;
    while (cubesClear() && time < 700) {
      intake(50);
      time += 10;
      wait(10);
    }

    intakeStop();
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
  ctrPrimary.Screen.print("Done");
  return 0;
}
