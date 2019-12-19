#include "RobotConfig.h"
#include "PID.h"

double yawAngle = 0;
double longitude = 0;
const double DIAMETER_CHASSIS = 12;
const double DIAMETER_WHEEL = 4;
PID longitudePID = PID(10.0/7.0, 0, 2.0/21.0, 0.01);//PID objects created
PID yawPID = PID(18.0/7.0, 0, 9.0/21.0, 0.01);
void resetPosition(){
    yawAngle = 0;
    longitude = 0;
    driveGyro.setRotation(0, degrees);
}
double getRotation(double distance){
    return (360*distance)/(M_PI * DIAMETER_WHEEL);
}
void turnToAngle(double angle){
    yawAngle = angle;
}
void driveToPos(double distance){//Drives the robot to an (x,y) coordinate
    longitude += getRotation(distance);
}
double longitudeError(){
    return longitude - (mtrLeft.rotation(degrees) + mtrRight.rotation(degrees))/2.0;
}
double yawError(){
    return yawAngle - driveGyro.angle(degrees);
}
int drivePID(){//Sets driver motors to specified rotation setting
    while (true){
        longitudePID.setPoint = longitude;
        yawPID.setPoint = yawAngle;
        double longitudeCurrent = (mtrLeft.rotation(degrees) + mtrRight.rotation(degrees))/2.0;
        double dLongitude = longitudePID.calculatePID(longitudeCurrent);
        double dYaw = yawPID.calculatePID(driveGyro.angle(degrees));
        Brain.Screen.printAt(1, 120, true, "Longitude: %f", longitude);
        Brain.Screen.printAt(1, 150, true, "Yaw: %f", yawAngle);
        if (dLongitude > maxSpeed){
            dLongitude = maxSpeed;
        }
        if (dYaw > maxSpeed){
            dYaw = maxSpeed;
        }
        if (dLongitude < -maxSpeed){
            dLongitude = -maxSpeed;
        }
        if (dYaw < -maxSpeed){
            dYaw = -maxSpeed;
        }
        chassisLeft(dLongitude + dYaw);
        chassisRight(dLongitude - dYaw);
        task::sleep(10);
    }
    return 0;
}
