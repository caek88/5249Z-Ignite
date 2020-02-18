/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.2.0                                            */
/*    File: PID.cpp                                             */
/*    Description: Defines methods in the PID class             */
/*--------------------------------------------------------------*/
#include "PID.h"

PID::PID(double kP, double kI, double kD, double samplePeriod){
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
    this->samplePeriod = samplePeriod;
}
double PID::calculatePID(double processVar){
    double error = setPoint - processVar;
    double derivative = (error - prevError)/samplePeriod;
    integral += error * samplePeriod;
    prevError = error;
    return error * kP + derivative * kD + integral * kI;
}
void PID::reset(){
    prevError = 0;
    integral = 0;
}
void PID::setGains(double kP, double kI, double kD){
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
}