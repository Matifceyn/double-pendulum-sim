#include "Runge_Kutta.h"

double rk4(Object o, double yn, double time, double dtime) {
	double k1,k2,k3,k4;
	
	k1 = o.accel(time, yn);
	k2 = o.accel(time + 0.5*dtime, yn + 0.5*dtime*k1);
	k3 = o.accel(time + 0.5*dtime, yn + 0.5*dtime*k2);
	k4 = o.accel(time + dtime, yn + dtime*k3);
	
	return yn + (1.0/6.0)*dtime*(k1 + k2 + k3 + k4);	
}

