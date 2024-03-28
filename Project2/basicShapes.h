#pragma once
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<thread>
#include<chrono>
#include<fstream>
#include<cstdlib>
using namespace std;
using std::this_thread::sleep_for;
COORD operator + (COORD,COORD);
struct pointers
{
	bool* alive;
	int* speed;
	COORD* inintalpos;
	bool* changed;
};
struct valuesToTimer
{
	bool* move;
	short* shoot;
	bool* sh;
};
class map
{
public:
	COORD borders;
	void check(COORD*);
	map();
	map(COORD);
	void makemap();
};
class block
{
public:
	COORD startc;
	COORD endc;
	COORD* relat;
	block(COORD,COORD,COORD*);
	bool isin(COORD);
	void set(COORD,COORD,COORD*);
};
void immu(bool*);
void tima(valuesToTimer);
void timd(valuesToTimer);
void sec(bool*);
COORD pcreatecoor(COORD);
COORD ecreatecoor(COORD);