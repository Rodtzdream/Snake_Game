#include "Snake.h"
#include "Game.h"

int main()
{
	//full screen console mode
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	// get handle to the console window
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// get screen buffer info
	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

	// current window size
	short winWidth = scrBufferInfo.srWindow.Right + 1;
	short winHeight = scrBufferInfo.srWindow.Bottom + 1;

	// current screen buffer size
	short scrBufferWidth = scrBufferInfo.dwSize.X;
	short scrBufferHeight = scrBufferInfo.dwSize.Y;

	// to remove the scrollbar
	COORD newSize;
	newSize.X = scrBufferWidth;
	newSize.Y = winHeight;
	SetConsoleScreenBufferSize(hOut, newSize);

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	srand(time(0));

	Menu(winWidth, winHeight);

	return 0;
}