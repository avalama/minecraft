#include "ships.h"
oriship::oriship(COORD inintalpos, COORD lastpos, int speed, bool alive,int size,COORD map) 
:inintalpos(inintalpos), lastpos(lastpos), alive(alive), speed(speed),size(size),map(map)
{	

}
bool oriship::isalive()
{
	if (alive)
	{
		return true;
	}
	return false;
}
COORD* oriship::askfor()
{
	return inin;
}
void oriship::move()
{
		COORD inisave = inintalpos, copy = inintalpos,lasave=lastpos;
  		for (short row = lasave.Y; row < (lasave.Y + size); row++)
		{
			int guud = hitbox[row - lasave.Y].endc.X + lasave.X;
			for (int cool = hitbox[row - lasave.Y].startc.X + lasave.X; cool < guud; cool++)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(cool),short(row) });
				cout << " ";
			}
		}
		{

			char f = 178;
			for (short row = inisave.Y; row < (inisave.Y + size); row++)
			{
				int guud = hitbox[row - inisave.Y].endc.X + inisave.X;
				for (int cool = hitbox[row - inisave.Y].startc.X + inisave.X; cool < guud; cool++)
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(cool),short(row) });
					cout << f;
				}
			}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(copy.X + 22),short(copy.Y - 4) });
			lastpos = copy;
			
		}
}
bool oriship::check(bullet help)
{
	if(!help.aluve())
	{
		for (int i = 0; i < size; i++)
		{
			if (hitbox[i].isin(help.getpos()))
			{
				return true;
			}
		}
	}
	return false;
}
bool* oriship::getdead()
{
	return &alive;
}
void oriship::sethitb(block old[])
{
	for (int i = 0; i < 9; i++)
	{
		this->hitbox[i].set(( & old[0] + i)->startc, (&old[0] + i)->endc, (&old[0] + i)->relat);
	}
}