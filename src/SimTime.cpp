#include "SimTime.h"

SimTime *st;

SimTime::SimTime(double dt) {
	dtime = dt;
}

void SimTime::step() {
	time += dtime;
}

double SimTime::getTime() {
	return time;
}

double SimTime::getStep() {
	return dtime;
}

