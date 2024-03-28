#include "ships.h"
spaceship::spaceship(COORD inintalpos,int speed,bool alive,COORD map):oriship(inintalpos,inintalpos,speed,alive,9,map)
{
	hitbox = (block*)calloc(9, sizeof(block));
	hitbox[0] ={ { 0, 0 }, { 1,0 }, inin };
	hitbox[1] ={ { 0,1  }, { 5,1 }, inin };
	hitbox[2] ={ { 0, 2 },{ 11,2 }, inin };
	hitbox[3] ={ { 0, 3 }, { 6,3 }, inin };
	hitbox[4] ={ { 0, 4 }, { 22,4 },inin };
	hitbox[5] ={ { 0, 5 }, { 6,5 }, inin };
	hitbox[6] ={ { 0, 6 }, { 11,6 },inin };
	hitbox[7] ={ { 0, 7 }, { 5,7 }, inin };
	hitbox[8] ={ { 0, 8 }, { 1,8 }, inin };
}
spaceship::spaceship(COORD inintalpos, int speed,COORD map)
:oriship(inintalpos, inintalpos, speed, true,9,map)
{
	hitbox = (block*)calloc(9, sizeof(block));
	hitbox[0] = { { 0, 0 }, { 1,0 }, inin };
	hitbox[1] = { { 0, 1 }, { 5,1 }, inin };
	hitbox[2] = { { 0, 2 },{ 11,2 }, inin };
	hitbox[3] = { { 0, 3 }, { 6,3 }, inin };
	hitbox[4] = { { 0, 4 }, { 22,4 },inin };
	hitbox[5] = { { 0, 5 }, { 6,5 }, inin };
	hitbox[6] = { { 0, 6 }, { 11,6 },inin };
	hitbox[7] = { { 0, 7 }, { 5,7 }, inin };
	hitbox[8] = { { 0, 8 }, { 1,8 }, inin };
}
spaceship::~spaceship()
{
	for (short row = lastpos.Y; row < (lastpos.Y + size);row++)
	{
		int guud = hitbox[row - lastpos.Y].endc.X + lastpos.X;
		for (int cool=hitbox[row-lastpos.Y].startc.X+lastpos.X;cool<guud;cool++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(cool),short(row) });
			cout << " ";
		}
	}
}
void up1(pointers poi) 
{
	while (*poi.alive)
	{

		sleep_for(chrono::microseconds(*poi.speed));
		if (GetAsyncKeyState(87))
		{
			poi.inintalpos->Y--;
		}
	}
}
void down1(pointers poi)
{
	while (*poi.alive)
	{
		sleep_for(chrono::microseconds(*poi.speed));
		if (GetAsyncKeyState(83))
		{
			poi.inintalpos->Y++;
		}
	}
}
void levt1(pointers poi)
{
	while (*poi.alive)
	{
		sleep_for(chrono::microseconds(*poi.speed));
		if (GetAsyncKeyState(65))
		{
			poi.inintalpos->X--;
		}
	}
}
void righ1(pointers poi)
{
	while (*poi.alive)
	{
		sleep_for(chrono::microseconds(*poi.speed));
		if (GetAsyncKeyState(68))
		{
			poi.inintalpos->X++;
		}
	}
}
void immu(bool *p)
{
	while (true)
	{
		if (GetAsyncKeyState(9))
		{
			*p = true;
		}
		else
		{
			*p = false;
		}
	}
}
void turbo1(int *speed)
{
	while (true)
	{
		if (GetAsyncKeyState(32))
		{
		}
	}
}
void spaceship::turbo()
{
	thread turb(turbo1, &speed);
	turb.detach();
}
void spaceship::up()
{
	thread u(up1, poi);
	u.detach();
}
void spaceship::down()
{
	thread dow(down1, poi);
	dow.detach();
}
void spaceship::levt()
{
	
	thread lev(levt1, poi);
	lev.detach();
}
void spaceship::righ()
{
	thread rig(righ1, poi);
	rig.detach();
}
void spaceship::initialize()
{
	turbo();
	up();
	down();
	levt();
	righ();
	imm();
}
void spaceship::imm()
{
	thread mmume(immu, &immume);
	mmume.detach();
}
void spaceship::recoil()
{
	int bulletNumber = findDead(h1);
	h1[bulletNumber].selfdestruct();
	h1[bulletNumber].setpos(gethead());
	h1[bulletNumber].revive();
}
void spaceship::hit()
{
	if(!immume)
	{
		hp--;
		if (hp < 1&&alive)
		{
			alive = false;
			this->~spaceship();
		}
	}
}
void spaceship::checkall(mybullet set[], int size)
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
void spaceship::checkall(enemybullet set[], int size)
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
COORD spaceship::gethead()
{
	COORD b={inintalpos.X+22,inintalpos.Y+4};
	return b;
}