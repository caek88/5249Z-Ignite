#include "RobotConfig.h"

int auton(){
    //deployRobot();
    int i = 1;
    while(true){
      if(i == 1){
        
        vex::task driveTask = task(drivePID);
        vex::task positionTask = vex::task(pos);
        driveToPos(12.0, 0);
      }
      i=2;
      task::sleep(1000);
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
