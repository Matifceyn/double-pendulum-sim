#ifndef OBJECT_H
#define OBJECT_H
#include <vector>

class Object {
	public:
		std::vector<double> pos;
		std::vector<double> vel;
	public:
		Object();
		~Object(void);
		void setPos(std::vector<double>);
		double accel(double, double);
		std::vector<double> getPos(void);
		std::vector<double> getVel(void);
		std::vector<double> getAcc(void);
		
		void move(); 
};
#endif

