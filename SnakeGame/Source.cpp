#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include "MainMenu.h"
#include "Settings.h"
#include <tchar.h>

void initialiseWindow()
{	
	int windowPositionX = WindowProperties::iWindowPosX;
	int windowPositionY = WindowProperties::iWindowPosY;
	int windowWidth = WindowProperties::iWindowWidth;
	int windowHeight = WindowProperties::iWindowHeight;

	// get handle to the console window
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// retrieve screen buffer info
	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

	// current window size
	short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

	// current screen buffer size
	short scrBufferWidth = scrBufferInfo.dwSize.X;
	short scrBufferHeight = scrBufferInfo.dwSize.Y;

	// to remove the scrollbar, make sure the window height matches the screen buffer height
	COORD newSize;
	newSize.X = scrBufferWidth;
	newSize.Y = winHeight;

	// set the new screen buffer dimensions
	int Status = SetConsoleScreenBufferSize(hOut, newSize);

	HWND window = GetConsoleWindow();
	MoveWindow(window, windowPositionX, windowPositionY, windowWidth, windowHeight, TRUE);
}

int main()
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE); //Set cursor to invisible.
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = FALSE;
	ci.dwSize = 30;
	SetConsoleCursorInfo(output, &ci);

	mciSendString(_T("play snakeMusic.mp3 repeat"), NULL, 0, 0); //Play background music.

	initialiseWindow();

	MainMenu menu; //Create instance of the 'MainMenu' on first instantiation.
	menu.update();


	return 0;
};