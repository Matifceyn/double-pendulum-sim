#ifndef SIMTIME_H
#define SIMTIME_H

class SimTime {
	private:
		double dtime;
		double time;
	public:
		SimTime(double);
		void step();
		double getTime();
		double getStep();
};

extern SimTime *st;

#endif
