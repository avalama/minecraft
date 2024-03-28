#include"bullets.h"
block::block(COORD start, COORD end,COORD* r):startc(start),endc(end),relat(r) //1
{
} 
bool block::isin(COORD bullet)
{
	COORD start = *relat + startc;
	COORD end = *relat + endc;
	if (bullet.Y >= end.Y && bullet.Y <= start.Y && bullet.X <= end.X && bullet.X >= start.X)
	{
		return true;
	}
	return false;
}
void block::set(COORD star, COORD en,COORD* r)
{
	startc = star;
	endc = en;
	relat = r;
}
void tima(valuesToTimer j) 
{
	while (true)
	{
		sleep_for(chrono::microseconds(30000));
  		*j.move = true;
 		*j.shoot=*j.shoot+1;
	}
}
void timd(valuesToTimer j) 
{
	while (true)
	{
		sleep_for(chrono::microseconds(20000));
		*j.sh = true;
	}
}
void sec(bool* frames)           //resets fps counter
{
	while (true)
	{ 
		sleep_for(1s);
		*frames = true;
	}
}