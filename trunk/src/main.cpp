#include <iostream>
#include <vector>

#include "Pendulum.h"
#include "Constants.h"
#include "SimTime.h"

#define TIMESTEP (1.0/3200.0)
#define ENDTIME 10.0

int main () {
	st = new SimTime(TIMESTEP);
	std::vector<double> pivot(3,0.0);
	Object o;
//	Pendulum p(1.0,1.0,PI/10.0,pivot);
	
	for (;;) {
		st->step();
		o.move();
		std::cout << st->getTime() << " " << o.getPos()[0] << " " << o.getPos()[1] << " " << o.getPos()[2] << std::endl;
	}
	
	return 0;
}


