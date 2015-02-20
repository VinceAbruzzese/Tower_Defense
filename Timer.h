//---------------------------------------------------------------------
//  Vince Abruzzese 
//  Class: Timer
//---------------------------------------------------------------------
//  The Timer class will be used for critters to move across the map
//  It will also be used for the shooting rate of Towers and the
//  spawn rate of critters
//---------------------------------------------------------------------

//REFERENCE: http://www.cplusplus.com/forum/beginner/317/

#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <conio.h>

class Timer
{
public:
	Timer();
	void start();
	void stop();
	void reset();
	bool isRunning();
	unsigned long getTime();
	bool isOver(unsigned long seconds);

private:
	bool resetted;
	bool running;
	unsigned long beginning;
	unsigned long end;
};

#endif
//End of Timer.h