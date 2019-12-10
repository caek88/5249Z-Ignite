#include "RobotConfig.h"
#include "PID.h"
double angle = 0.0;
const double DIAMETER_CHASSIS = 12;
const double DIAMETER_WHEEL = 4;
double startPoint[2] = {0,0};
double endPoint[2] = {0,0};
double maxSpeed = 80;
PID driveLeft = PID(10.0/7.0, 0, 4.0/42.0, 0.01);//PID objects created
PID driveRight = PID(10.0/7.0, 0, 4.0/42.0, 0.01);
double getRotation(double distance){
    return (360*distance)/(M_PI * DIAMETER_WHEEL);
}

double distanceToEnd(){//Calculates the robot's distance to the endline with a scalar projection
    double vectST[2] = {endPoint[0] - startPoint[0], endPoint[1] - startPoint[1]};//sets vector from start to the target
    double vectCT[2] = {endPoint[0] - xPosition, endPoint[1] - yPosition};//sets vector from current position to target
    return (vectST[0] * vectCT[0] + vectST[1] * vectCT[1])/sqrt(pow(vectST[0],2) + pow(vectST[1],2));//calculates scalar projection of CT onto ST
}
void turnToAngle(double finalAngle){//Turns the robot to a specific angle
    driveLeft.setGains(10.0/7.0, 0, 12.0/42.0);
    driveRight.setGains(10.0/7.0, 0, 12.0/42.0);
    double angleChange;
    maxSpeed -= 20;
    //Brain.Screen.printAt(1, 120, true, "Position Left: %f", finalAngle);
    do {
        angleChange = finalAngle - angle;//calculates the change in angle
        if (angleChange > 180){
            finalAngle -= 360;
            continue;
        }
        if (angleChange < -180){
            finalAngle += 360;
            continue;
        }
        double rotationToAngle = DIAMETER_CHASSIS/DIAMETER_WHEEL*angleChange;//calculates the rotation to finish the turn
        leftPosition = mtrLeft.rotation(vex::rotationUnits::deg) - rotationToAngle;//sets the motors to go to the correct rotation to turn to
        rightPosition = mtrRight.rotation(vex::rotationUnits::deg) + rotationToAngle;
        task::sleep(10);
    } while (fabs(angleChange) > 2.5);//waits for the angle to be within 0.2 away
    driveLeft.setGains(10.0/7.0, 0, 4.0/42.0);
    driveRight.setGains(10.0/7.0, 0, 4.0/42.0);
    maxSpeed += 20;
    task::sleep(200);
}

bool driveToPos(double xPos, double yPos, bool reversed, bool timeOut = false, int time = 5000, bool adjust = true){//Drives the robot to an (x,y) coordinate
    endPoint[0] = xPos;//Set the endpoint to the target
    endPoint[1] = yPos;
    startPoint[0] = xPosition;//set the start point to the current position
    startPoint[1] = yPosition;
    double vectSE[2] = {endPoint[0] - startPoint[0], endPoint[1] - startPoint[1]};//Set vector for angle direction
    //maxSpeed -= 20;
    if(adjust){
      turnToAngle((vectSE[1] >= 0?1:-1) * 180/M_PI * acos(vectSE[0]/sqrt(pow(vectSE[0], 2) + pow(vectSE[1], 2))) + (reversed?180:0));//calculate the angle difference and turn to that angle
    }
    //maxSpeed += 20;
    double distance;//Find distance to endline
    int timer = 0;//Timer for timeOut
    do {//While the robot is 0.5 inches away or time times out
        distance = distanceToEnd();
        leftPosition = mtrLeft.rotation(vex::rotationUnits::deg) + (reversed?-1:1)*getRotation(distance);//set motors to go the correct rotation
        rightPosition = mtrRight.rotation(vex::rotationUnits::deg) + (reversed?-1:1)*getRotation(distance);
        vex::task::sleep(10);
        timer += 10;
    } while (fabs(distance) > 0.5 && (!timeOut || !(timer <= time))) ;
    if (timeOut && timer > time){
        return false;
    }
    return true;
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
        
        task::sleep(10);
    }
    return 0;
}
int pos(){
    double oldR = 0.0;
    double oldL = 0.0;
    double oldH = 0.0;

    double encRInit = encRight.rotation(rotationUnits::deg);
    double encLInit = encLeft.rotation(rotationUnits::deg);
    double encHInit = encStrafe.rotation(rotationUnits::deg);
    while(true){
        double encRVal = -((encRight.rotation(rotationUnits::deg) - encRInit)) - oldR;
        double encLVal = -((encLeft.rotation(rotationUnits::deg) - encLInit)) - oldL;
        double encHVal = ((encStrafe.rotation(rotationUnits::deg) - encHInit)) - oldH;
        
        double encDistX = (encRVal + encLVal)/2.0;
        double encTheta = (encRVal - encLVal)/2.0;
        
        double deltaDistX = (M_PI * DIAMETER_WHEEL * encDistX)/(360.0);
        double deltaDistY = (M_PI * DIAMETER_WHEEL * encHVal)/(360.0);
        //double deltaTheta = (30.0 * encTheta)/(M_PI);
        double deltaTheta = (encTheta*DIAMETER_WHEEL)/DIAMETER_CHASSIS;
        
        angle += deltaTheta;
        xPosition += (deltaDistX * cos((angle * M_PI)/180.0)) - (deltaDistY * sin((angle * M_PI)/180.0));
        yPosition += (deltaDistX * sin((angle * M_PI)/180.0)) + (deltaDistY * cos((angle * M_PI)/180.0));
        
        oldR = encRVal + oldR;
        oldL = encLVal + oldL;
        oldH = encHVal + oldH;
        Brain.Screen.printAt(1,30,true,"X: %f", xPosition);
        Brain.Screen.printAt(1,60, true,"Y: %f", yPosition);
        Brain.Screen.printAt(1, 90, true,"A: %f", angle);
    }
    return 0;
}
