#include "RobotConfig.h"


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
