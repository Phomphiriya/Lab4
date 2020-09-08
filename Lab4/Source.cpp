#include<stdio.h>
#include <windows.h>
#include<conio.h>
void draw_ship()
{
	printf(" <-0-> ");
}
void erase_ship()
{
	printf("       ");
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	draw_ship();
	COORD d = { x, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
	erase_ship();
	COORD e = { x, y + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), e);
	erase_ship();
}

int main()
{
	char ch = ' ';
	int x = 20, y = 20;
	gotoxy(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x != 0) { gotoxy(x--, y); }
			if (ch == 'd' && x != 80) { gotoxy(x++, y); }
			if (ch == 'w' && y != 0) { ; gotoxy(x, y--); }
			if (ch == 's' && y != 30) { gotoxy(x, y++); }
			fflush(stdin);
		}
		Sleep(500);
	} while (ch != 'x');
	return 0;
}