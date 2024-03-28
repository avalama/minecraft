#include"bullets.h"
mybullet::mybullet(COORD* inin,COORD map,bool* parent):bullet(inin,map,parent)
{

}
void mybullet::kill()
{
	this->selfdestruct();
	this->setpos(pcreatecoor(*inin));
	hit = true;
}
void mybullet::move()
{
 	if (!hit)
	{
		if (position.X>map.X-3)
		{
        	hit = true;
 			this->~mybullet();
			selfdestruct();
		}else
		{
			position.X++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(position.X), position.Y });
			cout << ">";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(position.X - 1), position.Y });
			cout << " ";
		}
	}
}