#include <stdio.h>
#include <conio.h>
#include "cConsole.h"
using namespace std;

int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}


void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}


void gotoXY(int column, int line)
{
	ShowConsoleCursor(false);
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void DisableMouse() {
	DWORD prev_mode;
	_In_  HANDLE  hConsoleHandle;
	_Out_ LPDWORD lpMode;
	GetConsoleMode(hConsoleHandle, &prev_mode);
	SetConsoleMode(hConsoleHandle, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

void drawTitle()
{
	int base = 10;
	int baseX = 20;
	gotoXY(baseX, base);
	cout << "_____________________   _____  ________ _____.___._.   ________ ________ ._._._." << endl;
	gotoXY(baseX, base + 1);
	cout << "\______   \\_   _____/  /  _  \\ \\______ \\\\__  |   | |  /  _____/ \\_____  \\| | | |" << endl;
	gotoXY(baseX, base + 2);
	cout << " |       _/|    __)_  /  /_\\  \\ |    |  \\/   |   | | /   \\  ___  /   |   \\ | | |" << endl;
	gotoXY(baseX, base + 3);
	cout << " |    |   \\|        \\/    |    \\|    `   \\____   |\\| \\    \\_\\  \\/    |    \\|\\|\\|" << endl;
	gotoXY(baseX, base + 4);
	cout << " |____|_  /_______  /\\____|__  /_______  / ______|__  \\______  /\\_______  /_____" << endl;
	gotoXY(baseX, base + 5);
	cout << "        \\/        \\/         \\/        \\/\\/       \\/         \\/         \\/\\/\\/\\/" << endl;
	
}