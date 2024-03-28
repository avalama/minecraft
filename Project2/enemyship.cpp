#include "ships.h"
COORD enemyship::gethead()
{
	COORD b = { inintalpos.X-1,inintalpos.Y +2 };
	return b;
}
enemyship::enemyship(COORD inintalpos, int speed,COORD map) :oriship(inintalpos, inintalpos, speed, true,5,map)
{
	hitbox = (block*)calloc(9, sizeof(block));
	hitbox[0] = { { 10, 0 }, {11,0 },inin };
	hitbox[1] = { { 6 , 1 }, {11,1 },inin };
	hitbox[2] = { { 0 , 2 }, {11,2 },inin };
	hitbox[3] = { { 6 , 3 }, {11,3 },inin };
	hitbox[4] = { { 10, 4 }, {11,4 },inin };
}
enemyship::~enemyship()
{
	for (short row = lastpos.Y; row < (lastpos.Y + size); row++)
	{
		int guud = hitbox[row - lastpos.Y].endc.X + lastpos.X;
		for (int cool = hitbox[row - lastpos.Y].startc.X + lastpos.X; cool < guud; cool++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(cool),short(row) });
			cout << " ";
		}
	}
	hp = 3;
   	inintalpos = { short(map.X - 20),short(3 + rand() % (map.Y - 6)) };
	alive = true;
}
void enemyship::charge(bool* stoppingpower)
{
	inintalpos.X--;
	if (inintalpos.Y > map.Y - 8)
	{
		updown = true;
	}
	else
	{
		if (inintalpos.Y < 2)
		{
			updown = false;
		}
	}
	if (updown)
	{
		inintalpos.Y--;
	}
	else
	{
		inintalpos.Y++;
	}
	if (inintalpos.X < 1)
	{
		*stoppingpower = true;
	}
}
void enemyship::recoil()
{
		int bulletNumber = findDead(b1);
		b1[bulletNumber].selfdestruct();
		b1[bulletNumber].setpos(gethead());
		b1[bulletNumber].revive();
}
void enemyship::moveallstuff(bool* stop)
{
	if(isalive())
			{ 
				rollete++;
				if(rollete%3==0)
				{
					charge(stop);
				}
				if (rollete > 36)
				{
					rollete = 0;
					recoil();
				}
			}
}
void enemyship::hit()
{
	if (!immume)
	{
		hp--;
		if (hp < 1 && alive)
		{
			killedcounter++;
			alive = false;
			this->~enemyship();
		}
	}
}
void enemyship::checkall(mybullet set[], int size)
{
	for (int i = 0; i < size; i++)
	{
		mybullet* j = (&set[0] + i);
		if (this->check(*j))
		{
			j->kill();
			this->hit();
		}
	}

}
void enemyship::checkall(enemybullet set[], int size)
{
	for (int i = 0; i < size; i++)
	{
		enemybullet* j = (&set[0] + i);
		if (this->check(*j))
		{
			j->kill();
			this->hit();
		}
	}

}
int enemyship::getkilledamount()
{
	return killedcounter;
}