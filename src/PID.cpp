#include "PID.h"

using namespace std;


PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_)
{
    
     //Initialize PID controller with the coefficients as the input values.
    
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;

    p_error = 0 ;
    i_error = 0 ;
    d_error = 0 ;

}

void PID::UpdateError(double cte)
{
    //Updates error values for calculating total error below.
    // d_error is difference from old cte (p_error) to the new cte
    d_error = (cte - p_error);
    
    // p_error gets set to the new cte
    p_error = cte;
    
    // i_error is the sum of ctes to this point
    i_error += cte;
}

double PID::TotalError()
{
    // Return the total error of each coefficient multiplied by the respective error
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}
