#include "RobotConfig.h"
#include "PID.h"

const double DIAMETER_CHASSIS = 12;
const double DIAMETER_WHEEL = 4;
PID driveLeft = PID(10.0/7.0, 0, 4.0/42.0, 0.01);//PID objects created
PID driveRight = PID(10.0/7.0, 0, 4.0/42.0, 0.01);
double getRotation(double distance){
    return (360*distance)/(M_PI * DIAMETER_WHEEL);
}
bool turnToAngle(double finalAngle, double tolerance){//Turns the robot to a specific angle
    driveLeft.setGains(10.0/7.0, 0, 16.0/42.0);
    driveRight.setGains(10.0/7.0, 0, 16.0/42.0);
    double angleChange = finalAngle + driveGyro.angle(rotationUnits::deg);;//calculates the change in angle
    if (angleChange > 180){
        finalAngle -= 360;
        return false;
    }
    if (angleChange < -180){
        finalAngle += 360;
        return false;
    }
    double rotationToAngle = DIAMETER_CHASSIS/DIAMETER_WHEEL*angleChange;//calculates the rotation to finish the turn
    leftPosition = mtrLeft.rotation(vex::rotationUnits::deg) - rotationToAngle;//sets the motors to go to the correct rotation to turn to
    rightPosition = mtrRight.rotation(vex::rotationUnits::deg) + rotationToAngle;
    if(angleChange > 0){
        return angleChange > tolerance;
    }
    else{
        return angleChange < -tolerance;
    }
}
void driveToPos(double distance){//Drives the robot to an (x,y) coordinate
    driveLeft.setGains(10.0/7.0, 0, 4.0/42.0);
    driveRight.setGains(10.0/7.0, 0, 4.0/42.0);
    leftPosition = mtrLeft.rotation(vex::rotationUnits::deg) + getRotation(distance);//set motors to go the correct rotation
    rightPosition = mtrRight.rotation(vex::rotationUnits::deg) + getRotation(distance);
}
double driveDistance(){
    return fabs(leftPosition - mtrLeft.rotation(vex::rotationUnits::deg));
}
int drivePID(){//Sets driver motors to specified rotation setting
    while (true){
        driveLeft.setPoint = leftPosition;
        driveRight.setPoint = rightPosition;
        double speedLeft = driveLeft.calculatePID(mtrLeft.rotation(rotationUnits::deg));
        double speedRight = driveRight.calculatePID(mtrRight.rotation(rotationUnits::deg));
        Brain.Screen.printAt(1, 120, true, "Position Left: %f", leftPosition);
        Brain.Screen.printAt(1, 150, true, "Position Right: %f", rightPosition);
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
    }
    return 0;
}