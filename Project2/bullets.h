#pragma once
#include"basicShapes.h"
class bullet
{
protected:
	COORD* inin;
	COORD position;
	COORD map;
	bool* parentlife;
	bool hit = true;
	bullet(COORD*,COORD,bool*);
public:
	bool aluve();
	COORD getpos();
	void revive();
	void setpos(COORD);
	void selfdestruct();
};
class mybullet : public bullet
{
public:
	mybullet(COORD*,COORD,bool*);
	void move();
	void kill();
};
class enemybullet : public bullet
{
public:
	enemybullet(COORD*,COORD,bool*);
	void move();
	void kill();
};
int findDead(enemybullet[]);
int findDead(mybullet[]);
void moveall(mybullet[]);
void moveall(enemybullet[]);