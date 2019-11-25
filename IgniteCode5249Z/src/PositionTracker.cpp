#include "RobotConfig.h"

static double xPosition = 0.0;
static double yPosition = 0.0;
static double angle = 0.0;
const double DIAMETER_CHASSIS = 12;
const double DIAMETER_WHEEL = 4;
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
        xPosition += (deltaDistX * cos((angle * M_PI)/180.0)) - (deltaDistY * sin((angle * M_PI)/180.0));
        yPosition += (deltaDistX * sin((angle * M_PI)/180.0)) + (deltaDistY * cos((angle * M_PI)/180.0));
        
        oldR = encRVal + oldR;
        oldL = encLVal + oldL;
        oldH = encHVal + oldH;
    }
    return 0;
}
double getRotation(double distance){
    return (360*distance)/(M_PI * DIAMETER_WHEEL);
}