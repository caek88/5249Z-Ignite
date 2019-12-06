#include "RobotConfig.h"
#include "PID.h"
double maxSpeed = 80;
PID driveLeft = PID(10.0/7.0, 0, 4.0/42.0, 0.01);
PID driveRight = PID(10.0/7.0, 0, 4.0/42.0, 0.01);
int drivePID(){
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
double getRotation(double distance){
    return (360*distance)/(M_PI * DIAMETER_WHEEL);
}
double startPoint[2] = {0,0};
double endPoint[2] = {0,0};
double distanceToEnd(){
    double vectST[2] = {endPoint[0] - startPoint[0], endPoint[1] - startPoint[1]};
    double vectCT[2] = {endPoint[0] - xPosition, endPoint[1] - yPosition};
    return (vectST[0] * vectCT[0] + vectST[1] * vectCT[1])/sqrt(pow(vectST[0],2) + pow(vectST[1],2));
}
void turnToAngle(double finalAngle){
    double angleChange;
    do {
        angleChange = finalAngle - angle;
        double rotationToAngle = DIAMETER_CHASSIS/DIAMETER_WHEEL*angleChange;
        leftPosition = mtrLeft.rotation(vex::rotationUnits::deg) + rotationToAngle;
        rightPosition = mtrRight.rotation(vex::rotationUnits::deg) - rotationToAngle;
    } while (fabs(angleChange) > 0.2);
}

void driveToPos(double xPos, double yPos){
    endPoint[0] = xPos;
    endPoint[1] = yPos;
    startPoint[0] = xPosition;
    startPoint[1] = yPosition;
    double vectSE[2] = {endPoint[0] - startPoint[0], endPoint[1] - startPoint[1]};
    turnToAngle(M_PI / 180 * acos(vectSE[1]/sqrt(pow(endPoint[0], 2) + pow(endPoint[1], 2))));
    
    double distance = distanceToEnd();
    while (true) {
        leftPosition = mtrLeft.rotation(vex::rotationUnits::deg) + getRotation(distance);
        rightPosition = mtrRight.rotation(vex::rotationUnits::deg) + getRotation(distance);
        vex::task::sleep(10);
    }
}
int pos(){
    double oldR = 0.0;
    double oldL = 0.0;
    double oldH = 0.0;

    double encRInit = encRight.rotation(rotationUnits::deg);
    double encLInit = encLeft.rotation(rotationUnits::deg);
    double encHInit = encStrafe.rotation(rotationUnits::deg);
    while(true){
        double encRVal = ((encRight.rotation(rotationUnits::deg) - encRInit)) - oldR;
        double encLVal = ((encLeft.rotation(rotationUnits::deg) - encLInit)) - oldL;
        double encHVal = ((encStrafe.rotation(rotationUnits::deg) - encHInit)) - oldH;
        
        double encDistX = (encRVal + encLVal)/2.0;
        double encTheta = (encRVal - encLVal)/2.0;
        
        double deltaDistX = (M_PI * encDistX)/(90.0);
        double deltaDistY = (M_PI * encHVal)/(90.0);
        //double deltaTheta = (30.0 * encTheta)/(M_PI);
        double deltaTheta = (encTheta*DIAMETER_WHEEL)/DIAMETER_CHASSIS;
        
        angle += deltaTheta;
        yPosition += (deltaDistX * cos((angle * M_PI)/180.0)) - (deltaDistY * sin((angle * M_PI)/180.0));
        xPosition += (deltaDistX * sin((angle * M_PI)/180.0)) + (deltaDistY * cos((angle * M_PI)/180.0));
        
        oldR = encRVal + oldR;
        oldL = encLVal + oldL;
        oldH = encHVal + oldH;
        Brain.Screen.printAt(1,30,true,"X: %f", xPosition);
        Brain.Screen.printAt(1,60, true,"Y: %f", yPosition);
        Brain.Screen.printAt(1, 90, true,"A: %f", angle);
    }
    return 0;
}
