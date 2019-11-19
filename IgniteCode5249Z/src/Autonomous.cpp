#include "RobotConfig.h"
#include "PID.h"
int auton(){
    PID driveForward = PID(1, 0, 0, 0.01);
    driveForward.setPoint = 100;
    while(true){
        double speed = driveForward.calculatePID(mtrLeft.rotation(rotationUnits::deg));
        mtrLeft.spin(directionType::fwd, speed, velocityUnits::pct);
    }
    return 0;
}