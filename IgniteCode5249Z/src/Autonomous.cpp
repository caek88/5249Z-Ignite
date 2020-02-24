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
  if (autonMode == 6){
      setOriginalLight();
      while (true){
          Brain.Screen.printAt(1, 30, true, "%d", cubesClear()?1:0);
          wait(20);
      }
  }
  /*---------------*/
  /*    Auton 1    */
  /*---------------*/
  if (autonMode == 1) { // Tries to get 8 cubes, cubes may cross the auton line
                        // - use in skills
    vex::task driveTask = task(drivePID);
    resetPosition();
    setOriginalLight();

    // Move forward to get 4 cubes
    intake(-100);
    wait(400);
    intake(0);
    maxSpeed = 35;
    driveToPos(40);
    while (longitudeError() > 0.5) {
      if (38 - longitudeError() > 3) {
        intake(-100);
      }
      wait(10);
    }
    wait(300);

    // Angle for next cube
    maxSpeed = 20;
    turnToAngle(22);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    // Pick up cube
    maxSpeed = 40;
    driveToPos(12);
    intake(-100);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);

    // Move back
    //intakeStop();
    maxSpeed = 40;
    intake(-100);
    driveToPos(-8);
    while (longitudeError() > 0.5) {
      wait(10);
    }
    intake(20);
    wait(300);
    intakeStop();

    //turn around for blue tower
    maxSpeed = 20;
    turnToAngle(-112);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    //move forward and place cube in blue tower
    intakeStop(hold);
    driveToPos(10);
    while (!liftArm(lowPos)){
        if (mtrRampLift.rotation(degrees) < 200){
            rampLift(80);
        } else {
            rampLiftStop(hold);
        }
        wait(10);
    }

    //reset arms aand go back to mid tower
    mtrArm.stop(hold);
    intake(50);
    wait(1500);
    intake(-100);
    driveToPos(-5);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    while (!liftArm(downPos)){
        wait(10);
        if (!limRamp.pressing() && mtrArm.rotation(degrees) > -150){
            liftRamp(false);
        }
    }
    mtrArm.stop(hold);
    rampLiftStop();
    wait(200);

    //turn around for tower
    maxSpeed = 30;
    turnToAngle(26);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    intake(30);
    wait(500);

    //Place cube in mid tower
    intakeStop(hold);
    driveToPos(13);
    while (!liftArm(lowPos)){
        if (mtrRampLift.rotation(degrees) < 200){
            rampLift(80);
        } else {
            rampLiftStop(hold);
        }
        wait(10);
    }
    intake(50);
    wait(1000);
    intake(-100);

    //back up to be in line with row of cubes
    driveToPos(-8);
    wait(1000);
    while (!liftArm(downPos)){
        wait(10);
        if (!limRamp.pressing() && mtrArm.rotation(degrees) > -150 && longitudeError() > -4){
            liftRamp(false);
        }
    }
    mtrArm.stop(hold);
    rampLiftStop();
    wait(500);

    //angle for row of cubes
    maxSpeed = 30;
    turnToAngle(5);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    //intake the row of 5 cubes (61)
    maxSpeed = 40;
    driveToPos(14);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);

    maxSpeed = 40;
    driveToPos(-14);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);

    maxSpeed = 30;
    turnToAngle(-2);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    maxSpeed = 40;
    driveToPos(12);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);

    maxSpeed = 30;
    turnToAngle(2);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    maxSpeed = 40;
    driveToPos(12);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);

    maxSpeed = 40;
    driveToPos(40);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(3000);

    
    //turn for red tower
    maxSpeed = 20;
    turnToAngle(-96);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    intake(15);
    wait(500);

    //Place cube in red tower
    intakeStop(hold);
    //driveToPos(15);
    while (!liftArm(lowPos)){
        if (mtrRampLift.rotation(degrees) < 200){
            rampLift(80);
        } else {
            rampLiftStop(hold);
        }
        wait(10);
    }
    mtrArm.stop(hold);

    maxSpeed = 27;
    driveToPos(6);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    intake(30);
    wait(1500);

    //Move back for stacking
    intake(-100);
    driveToPos(-16);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    while (!liftArm(downPos)){
        wait(10);
        if (!limRamp.pressing() && mtrArm.rotation(degrees) > -150){
            liftRamp(false);
        }
    }
    mtrArm.stop(hold);
    rampLiftStop();
    wait(1000);

    //turn for scoring
    maxSpeed = 30;
    turnToAngle(-48);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(1000);

    //place stack in red zone
    maxSpeed = 40;
    driveToPos(26);
    while (longitudeError() > 0.5) {
      if (longitudeError() < 7) {
        maxSpeed = 15;
        intakeStop(coast);
      }
      if (26 - longitudeError() > 6) {
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
  

    /*maxSpeed = 40;
    driveToPos(20);
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
    intakeStop();*/
    /*
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
    */
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
  //4 cubes in protected
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
    turnToAngle(colorMod * 91);
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
    turnToAngle(colorMod * 133);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    intake(50);
    wait(500);
    
    intakeStop();
    maxSpeed = 15;
    driveToPos(6);
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
