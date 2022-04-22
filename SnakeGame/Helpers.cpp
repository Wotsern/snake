#include <iostream>

#include "Helpers.h"
#include "Windows.h"

void gotoXY(int x, int y) //Set cursor position.
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hStdout, position);
}

void drawChar(char c, int x, int y) { //Draw a specific character in a set location.
	gotoXY(x, y); 
	std::cout << c;
}

void drawScore(int text, int x, int y) //Used to draw score.
{
	gotoXY(x, y);
	std::cout << "Score: " << text;
}

void color(int color) //Used for setting colors.
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y) { //Used globally for positioning.
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
