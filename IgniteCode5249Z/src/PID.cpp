#include "PID.h"

PID::PID(double kProportional, double kIntegral, double kDerivative, double period){
    kP = kProportional;
    kI = kIntegral;
    kD = kDerivative;
    samplePeriod = period;
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