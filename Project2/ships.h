#pragma once
#include"basicShapes.h"
#include"bullets.h"
class oriship                             //root of all ships
{
protected:
	COORD inintalpos;
	COORD* inin = &inintalpos;
	COORD lastpos;
	COORD map;
	bool immume = false;
	bool alive = true;
	int speed;
	int size;
	int hp = 3;
	int rollete = 0;
	pointers poi{&alive,&speed,inin};
	block j= { { 0, 0 }, { 1,0 }, inin };
	block* hitbox=&j;
	oriship(COORD, COORD, int, bool,int,COORD);
public:
	bool* getdead();
	void sethitb(block[]);
	COORD* askfor();
	void move();
	bool isalive();
	bool check(bullet);
};
class spaceship :public oriship //my ship
{
	void hit();
public:
	mybullet h1[20] = { {inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive}
					   ,{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive}
					   ,{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive}
					   ,{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive} };
	~spaceship();
	spaceship(COORD, int, bool,COORD);
	spaceship(COORD, int,COORD);
	COORD gethead();
	void checkall(enemybullet[], int);
	void checkall(mybullet[],int);
	void up();
	void turbo();
	void down();
	void levt();
	void righ();
	void initialize();
	void imm();
	void recoil();
};
class enemyship :public oriship //yes thats enemy ship
{
	int killedcounter;
	bool updown = true;
	void hit();
public:
	enemybullet b1[20]{ {inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive}
					   ,{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive}
					   ,{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive}
					   ,{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive},{inin,map,&alive} };
	int getkilledamount();
	~enemyship();
	enemyship(COORD, int, COORD);
	COORD gethead();
	void checkall(enemybullet[], int);
	void checkall(mybullet[], int);
	void recoil();
	void charge(bool*);
	void moveallstuff(bool*);
};