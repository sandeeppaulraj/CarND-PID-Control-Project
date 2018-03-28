#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	/* 
	 * this keyword is required since function parameter
	 * name is same as class member name.
	 */
	this->Kp = Kp;
	this->Kd = Kd;
	this->Ki = Ki;
	
	p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
	
}

void PID::UpdateError(double cte) {
	/* first calculate the differential error since the previous value is required */
	d_error = cte - p_error;
	
	p_error = cte;
	
	i_error += cte;
}

double PID::TotalError() {
	return -((Kp*p_error) + (Kd*d_error) + (Ki*i_error));
}

