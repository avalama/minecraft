#include"bullets.h"
bullet::bullet(COORD* inin, COORD map,bool*parent) :inin(inin),position(position), map(map),parentlife(parent)
{

}
void bullet::selfdestruct() 
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(position.X),position.Y });
	cout <<" ";
}//2
bool bullet::aluve()
{
	return hit;
}
void bullet::setpos(COORD reqired)
{
   	position = reqired;
}
void bullet::revive()
{
	hit = false;
}
int findDead(enemybullet set[])
{
	for (int i = 0; i < 20; i++)
	{
		if ((&set[0] + i)->aluve())
		{
			return i;
		}
	}
	int thi, last = 999, anas = 0;
	for (int i = 0; i < 20; i++)
	{
		thi = (&set[0] + i)->getpos().X;
		if (thi < last)
		{
			anas = i;
		}
		last = thi;
	}
	return anas;
}
int findDead(mybullet set[])
{
	for (int i = 0; i <20; i++)
	{
		if ((&set[0] + i)->aluve())
		{ 
			return i;
		}
	}
 	int thi, last =0,anas=0;
	for (int i = 0; i <20; i++)
	{
		thi = (&set[0] + i)->getpos().X;
		if (thi>last)
		{
			anas=i;
		}
		last = thi;
	}
	return anas;
}
void moveall(mybullet set[])
{
	for (int i = 0; i < 20; i++)
	{
		(& set[0] + i)->move();
	}
}
void moveall(enemybullet set[])
{

	for (int i = 0; i < 20; i++)
	{
		enemybullet* p = (&set[0] + i);
		p->move();
	}
}
COORD bullet::getpos()
{
	return position;
}