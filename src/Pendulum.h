#ifndef PENDULUM_H
#define PENDULUM_H

#include <vector>
#include "Object.h"

class Pendulum : public Object {

	protected:
		double length;
		double mass;
		std::vector<double> pivot;
	public:
		Pendulum(double, double, double, std::vector<double>);
		~Pendulum();
		void move(double);
	
};


#endif

