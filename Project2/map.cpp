#include"basicShapes.h"
	map::map():borders{100,30}
	{
		makemap();
	};
	map::map(COORD pos) :borders(pos)
	{
		makemap();
	}
	void map::makemap()
	{
		char p = 219;
		short lengthp = borders.X, highp = borders.Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		for (short i = 0; i <= lengthp; i++)
		{
			cout << p;
		}
		for (short j = 0; j <= borders.Y; j++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,j });
			cout << p;
		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,highp });
		for (int i = 0; i <= lengthp; i++)
		{
			cout << p;
		}
		for (short j = 0; j <= borders.Y; j++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { lengthp,j });
			cout << p;
		}

	}
	void map::check(COORD* pos)
    { 
		if (pos->Y >= (borders.Y-10))
		{
			pos->Y = borders.Y - 11;
		}
		if (pos->Y < 2)
		{
			pos->Y = 2;
		}
		if (pos->X >= (borders.X - 26))
		{
			pos->X = borders.X - 26;
		}
		if (pos->X < 6)
		{
			pos->X = 6;
		}

}
	COORD operator +(COORD a, COORD b)
	  {
		  COORD dp = { a.X + b.X,a.Y + b.Y };
		  return dp;
	  }
	COORD pcreatecoor(COORD j)
{
	return{ short(j.X + 23), short(j.Y + 4) };
}
	COORD ecreatecoor(COORD j)
{
	return{short(j.X-1 ), short(j.Y +2)};
}