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
  if (autonMode == 1) { //skills
    vex::task driveTask = task(drivePID);
    resetPosition();
    setOriginalLight();

    // Move forward to get 4 cubes
    intake(-100);
    wait(400);
    intake(0);
    maxSpeed = 35;
    driveToPos(42);
    while (longitudeError() > 0.5) {
      if (40 - longitudeError() > 3) {
        intake(-100);
      }
      wait(10);
    }
    wait(300);

    //turn for mid tower
    maxSpeed = 25;
    turnToAngle(22);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    intake(30);
    wait(500);
    intakeStop();

    //Place cube in mid tower
    intakeStop(hold);
    maxSpeed = 20;
    driveToPos(9);
    while (!liftArm(lowPos)){
        if (mtrRampLift.rotation(degrees) < 200){
            rampLift(80);
        } else {
            rampLiftStop(hold);
        }
        wait(10);
    }
    mtrArm.stop(hold);
    //wait(500);
    

    maxSpeed = 30;
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    intake(35);
    wait(1000);
    intake(-100);

    //back up to be in line with row of cubes
    driveToPos(-13);
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
    maxSpeed = 20;
    turnToAngle(1);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    //intake the row of 5 cubes
    maxSpeed = 20;
    driveToPos(18);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(500);

    maxSpeed = 40;
    driveToPos(62);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    wait(1700);

    
    //turn for red tower
    maxSpeed = 20;
    turnToAngle(-120);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    intake(30);
    wait(300);

    //Place cube in red tower
    intakeStop(hold);
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
    driveToPos(8);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    intake(40);
    wait(1500);

    //Move back for stacking
    intake(-100);
    driveToPos(-8);
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
    maxSpeed = 25;
    turnToAngle(-47);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(600);

    //place stack in red zone
    maxSpeed = 40;
    driveToPos(13);
    while (longitudeError() > 0.5) {
      if (longitudeError() < 7) {
        maxSpeed = 15;
        intakeStop(coast);
      }
      if (13 - longitudeError() > 6) {
        liftRamp(true);
      }
      wait(10);
    }
    intakeStop(coast);
    while (!liftRamp(true)) {
      wait(10);
    }
    rampLiftStop(hold);
    wait(500);

    
    // Stack and move back
    intake(100);
    maxSpeed = 20;
    driveToPos(-15);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    intakeStop();

    //turn for high tower
    maxSpeed = 30;
    turnToAngle(90);
    while (fabs(yawError()) > 2.0) {
      if (!limRamp.pressing()){
          liftRamp(false);
      } else {
          rampLiftStop();
      }
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);
    intake(-100);
    rampLiftStop();

    //Drive forward to get cube
    maxSpeed = 50;
    driveToPos(39);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    intakeStop(hold);
    wait(500);

    driveToPos(-6);
    while (!liftArm(highPos)){
        if (mtrRampLift.rotation(degrees) < 200){
            rampLift(80);
        } else if(mtrRampLift.rotation(degrees) >= 200){
            rampLiftStop(hold);
        } else {
            rampLiftStop(hold);
        }
        wait(10);
    }
    mtrArm.stop(hold);

    maxSpeed = 27;
    driveToPos(11);
    while (fabs(longitudeError()) > 0.5) {
      wait(10);
    }
    intake(70);
    wait(800);


    intake(-100);
    driveToPos(-6);
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

    //turn for row of cubes
    maxSpeed = 20;
    turnToAngle(180);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    wait(500);

    maxSpeed = 35;
    intake(-100);
    driveToPos(86);
    while (fabs(longitudeError()) > 0.5) {
      if (longitudeError() > 31 && longitudeError() < 36){
          maxSpeed = 25;
      } else {
          maxSpeed = 35;
      }
      wait(10);
    }
    wait(500);

    //turn for blue goal zone
    maxSpeed = 20;
    turnToAngle(-125);
    while (fabs(yawError()) > 2.0) {
      if (fabs(yawError()) < 10) {
        maxSpeed = 10;
      }
      wait(10);
    }
    intake(20);
    wait(500);
    intakeStop();

    //place stack in blue zone
    maxSpeed = 40;
    driveToPos(42);
    int time = 0;
    while (longitudeError() > 0.5 && time < 4000) {
      if (longitudeError() < 7) {
        maxSpeed = 15;
        intake(20);
      }
      if (42 - longitudeError() > 8) {
        liftRamp(true);
      }
      wait(10);
      time += 10;
    }
    intakeStop(coast);
    while (!liftRamp(true) && time < 5000) {
      wait(10);
      time += 10;
    }
    rampLiftStop(hold);

    
    // Stack and move back
    intake(100);
    maxSpeed = 40;
    driveToPos(-15);
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

    intakeStop();
    maxSpeed = 30;
    driveToPos(30);
    while (longitudeError() > 0.5) {
      if (longitudeError() < 7) {
        maxSpeed = 15;
        intakeStop(coast);
      }
      if (30 - longitudeError() > 4) {
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
    driveToPos(23);
    while (longitudeError() > 0.5) {
      if (19 - longitudeError() > 3) {
        intake(-100);
      }
      wait(10);
    }
    wait(500);
    intake(-100);
    /*// Turn to tower
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
    */
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
    driveToPos(21);
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
    intake(60);
    wait(600);
    
    intakeStop();
    maxSpeed = 15;
    driveToPos(7);
    while (longitudeError() > 0.5) {
      task::sleep(10);
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
