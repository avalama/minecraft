#include"basicShapes.h"
#include"bullets.h"
#include"ships.h"
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	srand( time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) //only way to get ACTUAL random number
		 * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL)
		 * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) * time(NULL) );
	bool moveTimer = true,shoot=true,swich=true,stoppingpower=false;
	short color = 1, shootingCooldown = 0, l = rand() % 50,counter=0,kon=0;
	long enemybulletNumber = 0,bulletNumber=0;
	valuesToTimer timer1{&moveTimer,&shootingCooldown,&shoot};
	thread timeset1(tima,timer1);
	thread timeset2(timd,timer1); 
	thread fpsCount(sec,&swich);           //resets all values in per 400ms
	timeset1.detach();
	timeset2.detach();
	fpsCount.detach();
	map map1;
	spaceship p1({ 40,11}, 10000, {map1.borders});
	enemyship e1({80,20}, 10000, {map1.borders});
	enemyship e2({80,25}, 10000, {map1.borders});
	p1.initialize();
	map1.makemap();
	p1.move();
	while (true)
	{
		map1.check(p1.askfor());
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
 		if (p1.isalive())
		{
 			if (GetAsyncKeyState(32) && shootingCooldown >5)
			{
				shootingCooldown = 0;
				p1.recoil();
			}
		}
  	 	if (shoot)
		{
 			shoot = false;
			e1.moveallstuff(&stoppingpower);
			e2.moveallstuff(&stoppingpower);
			if (stoppingpower)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short((map1.borders.X/2)-3),short(map1.borders.Y / 2) });
				cout << "u died";
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short((map1.borders.X / 2) - 3),short((map1.borders.Y / 2)+1) });
				cout << "u killed " << (e1.getkilledamount() + e2.getkilledamount()) << " ships,congrats!";
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 110,9009 });
				cout << ".";
				return 0;
			}
 			moveall(p1.h1);
		}
 		if (moveTimer)
		{
			moveTimer = false;
			if (p1.isalive())
			{
				p1.move();
			}else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short((map1.borders.X / 2) - 3),short(map1.borders.Y / 2) });
				cout << "u died";
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short((map1.borders.X / 2) - 3),short((map1.borders.Y / 2) + 1) });
				cout << "u killed " << (e1.getkilledamount() + e2.getkilledamount()) << " ships,congrats!";
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 110,400 });
				return 0;
			}
			p1.checkall(e1.b1, 5);
			if(e1.isalive())
			{
				e1.move();
				e1.checkall(p1.h1,20);
			}
			moveall(e1.b1);
			if (e2.isalive())
			{
				e2.move();
				e2.checkall(p1.h1, 20);
			}
			p1.checkall(e2.b1, 5);
			moveall(e2.b1);
			kon++;
			if (kon > 200)
			{
				kon = 0;
				system("CLS");
				map1.makemap();
			}
		}
	}
}