/*--------------------------------------------------------------*/
/*    5249Z-Ignite                                              */
/*    Version: 1.2.0                                            */
/*    File: PID.h                                               */
/*    Description: header file for PID class                    */
/*--------------------------------------------------------------*/
#include "RobotConfig.h"

class PID {
    private:
        double kP, kI, kD;
        double integral = 0;
        double prevError;
        double samplePeriod;
    public: 
        PID(double, double, double, double);
        double setPoint;
        double calculatePID(double);
        void setGains(double, double, double);
        void reset();
};