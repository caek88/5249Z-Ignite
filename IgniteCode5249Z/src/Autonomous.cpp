#include "RobotConfig.h"
#include "PID.h"
double maxSpeed = 80;
PID driveLeft = PID(10.0/7.0, 0, 4.0/42.0, 0.01);
PID driveRight = PID(10.0/7.0, 0, 4.0/42.0, 0.01);
int drivePID(){
    driveLeft.setPoint = leftPosition;
    driveRight.setPoint = rightPosition;
    while (true){
        double speedLeft = driveLeft.calculatePID(mtrLeft.rotation(rotationUnits::deg));
        double speedRight = driveLeft.calculatePID(mtrLeft.rotation(rotationUnits::deg));
        if (speedLeft > maxSpeed){
            speedLeft = maxSpeed;
        }
        if (speedRight > maxSpeed){
            speedRight = maxSpeed;
        }
        if (speedLeft < -maxSpeed){
            speedLeft = -maxSpeed;
        }
        if (speedRight < -maxSpeed){
            speedRight = -maxSpeed;
        }
        mtrLeft.spin(directionType::fwd, speedLeft, velocityUnits::pct);
        mtrLeftFront.spin(directionType::fwd, speedLeft, velocityUnits::pct);
        mtrRight.spin(directionType::fwd, speedRight, velocityUnits::pct);
        mtrRightFront.spin(directionType::fwd, speedRight, velocityUnits::pct);
        task::sleep(10);
    }
}

int auton(){
    deployRobot();
    task driveTask = task(drivePID);
    task positionTask = task(pos);

    return 0;
}
