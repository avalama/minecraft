#include"bullets.h"
enemybullet::enemybullet(COORD* inin,COORD map,bool* parent):bullet(inin,map,parent)
{

}
void enemybullet::kill()
{
	this->selfdestruct();
	hit = true;
}
void enemybullet::move()
{
	if (!hit)
	{
		position.X--;
		if (position.X < 2)
		{
			this->kill();
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(position.X), position.Y });
		cout << "<";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(position.X + 1), position.Y });
		cout << " ";
	}
}