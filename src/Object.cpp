#include "Object.h"
#include "Constants.h"
#include "SimTime.h"
#include "Runge_Kutta.h"


Object::Object() {
	pos.assign(3, 0.0);
	vel.assign(3, 0.0);
}

Object::~Object(void) {
//	std::cout << "Destroying Object" << std::endl;
}

void Object::setPos(std::vector<double> pos_in) {
	pos = pos_in;
}


std::vector<double> Object::getPos(void) {
	return pos;
}

void Object::move() {
//	std::cout << "Moving" << std::endl;

// Falling
	vel[1] = rk4(*this, vel[1], st->getTime(), st->getStep());
}

double Object::accel(double t, double y) {
	return -G;
}


