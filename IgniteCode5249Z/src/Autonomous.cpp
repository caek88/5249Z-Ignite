#include "RobotConfig.h"
#include "PID.h"
int auton(){
    PID driveForward = PID(10.0/7.0, 0, 4.0/42.0, 0.01);
    driveForward.setPoint = 1000;
    while(true){
        double speed = driveForward.calculatePID(mtrLeft.rotation(rotationUnits::deg));
        if (speed > 80){
            speed = 80;
        }
        if (speed < -80){
            speed = -80;
        }
        mtrLeft.spin(directionType::fwd, speed, velocityUnits::pct);
        mtrRight.spin(directionType::fwd, speed, velocityUnits::pct);
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("%f", mtrLeft.rotation(rotationUnits::deg));
        task::sleep(10);
    }
    return 0;
}