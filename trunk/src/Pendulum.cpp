#include "Pendulum.h"
#include "Constants.h"
#include <math.h>
#include <iostream>

// Create a pendulum with string length l, mass m, initial angle theta, and pivot position piv.
Pendulum::Pendulum(double l, double m, double theta, std::vector<double> piv) : Object() {
	length = l;
	mass = m;
	pivot = piv;
	pos[0] = piv[0]+sin(theta)*length;
	pos[1] = piv[1]-cos(theta)*length;
}


Pendulum::~Pendulum () {
	
}

void Pendulum::move(double dt) {
// Swinging Motion
//-----------------
	// Zero Force
	std::vector<double> force;
	force.assign(3, 0.0);
	
	// Gravity
	force[1] += mass*-G;
	
	for(int i=0; i<3; i++) {
		// Centripital force
		force[i] += mass*(vel[0]*vel[0] + vel[1]*vel[1] + vel[2]*vel[2])*(pivot[i]-pos[i]) / (length*length);
		// Pendulum string
		force[i] += mass*G*(pivot[i]-pos[i]/length);
	}

	
	// Integrate
	for(int i=0; i<3; i++) pos[i] += vel[i]*dt;
	for(int i=0; i<3; i++) vel[i] += (force[i]/mass)*dt;
	
}

