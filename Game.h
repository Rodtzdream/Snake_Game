#pragma once
#include "Snake.h"

float target_time = 0.0000025;

void setCursorPosition(int x, int y);
void Menu(short width, short height);
void Settings(short width, short height);
void Play(short width, short height);
void Pause(short width, short height);
void Loss(short width, short height, short Score);

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void Menu(short width, short height)
{
	short choice = 3;
	while (true)
	{
		Sleep(50);
		system("cls");

		setCursorPosition(width / 2 - 20, height / 2 - 5);
		cout << "              Snake!               ";
		setCursorPosition(width / 2 - 20, height / 2 - 4);
		cout << "===================================";
		setCursorPosition(width / 2 - 20, height / 2 - 3);
		cout << "==             Play              ==";
		setCursorPosition(width / 2 - 20, height / 2 - 2);
		cout << "==           Settings            ==";
		setCursorPosition(width / 2 - 20, height / 2 - 1);
		cout << "==             Exit              ==";
		setCursorPosition(width / 2 - 20, height / 2 - 0);
		cout << "===================================";
		setCursorPosition(width / 2 - 23, height / 2 - choice);
		cout << ">>";
		setCursorPosition(width / 2 + 16, height / 2 - choice);
		cout << "<<";

		if (GetAsyncKeyState(VK_UP) && choice < 3)
			choice++;
		if (GetAsyncKeyState(VK_DOWN) && choice > 1)
			choice--;
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (choice == 3)
			{
				Play(width, height);
				return;
			}
			else if (choice == 2)
			{
				Settings(width, height);
			}
			else if (choice == 1)
			{
				system("cls");
				exit(0);
			}
		}
	}
}

void Settings(short width, short height)
{
	short choice = 3;
	while (true)
	{
		Sleep(50);
		system("cls");

		setCursorPosition(width / 2 - 20, height / 2 - 5);
		cout << "         Select Difficult          ";
		setCursorPosition(width / 2 - 20, height / 2 - 4);
		cout << "===================================";
		setCursorPosition(width / 2 - 20, height / 2 - 3);
		cout << "==             Easy              ==";
		setCursorPosition(width / 2 - 20, height / 2 - 2);
		cout << "==            Normal             ==";
		setCursorPosition(width / 2 - 20, height / 2 - 1);
		cout << "==             Hard              ==";
		setCursorPosition(width / 2 - 20, height / 2 - 0);
		cout << "===================================";
		setCursorPosition(width / 2 - 23, height / 2 - choice);
		cout << ">>";
		setCursorPosition(width / 2 + 16, height / 2 - choice);
		cout << "<<";

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			return;
		}
		if (GetAsyncKeyState(VK_UP) && choice < 3)
			choice++;
		if (GetAsyncKeyState(VK_DOWN) && choice > 1)
			choice--;
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (choice == 3)
				target_time = 0.0000025;
			else if (choice == 2)
				target_time = 0.000001;
			else if (choice == 1)
				target_time = 0.0000005;
			return;
		}
	}
}

void Play(short width, short height)
{
	system("cls");
	Snake Snake(width, height);
	float time;
	while (true)
	{
		Sleep(1);
		time = 0;
		Snake.Update();

		//timer
		while (time < target_time)
		{
			Sleep(1);
			auto start = chrono::high_resolution_clock::now();
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float> duration = end - start;
			time += duration.count();
		}
		if (target_time > 0.00000008)
			target_time -= 0.0000000002;
	}
	return;
}

void Pause(short width, short height)
{
	short choice = 3;
	while (true)
	{
		Sleep(50);
		system("cls");

		setCursorPosition(width / 2 - 20, height / 2 - 5);
		cout << "               Pause               ";
		setCursorPosition(width / 2 - 20, height / 2 - 4);
		cout << "===================================";
		setCursorPosition(width / 2 - 20, height / 2 - 3);
		cout << "==            Return             ==";
		setCursorPosition(width / 2 - 20, height / 2 - 2);
		cout << "==            Restart            ==";
		setCursorPosition(width / 2 - 20, height / 2 - 1);
		cout << "==           Main menu           ==";
		setCursorPosition(width / 2 - 20, height / 2 - 0);
		cout << "===================================";
		setCursorPosition(width / 2 - 23, height / 2 - choice);
		cout << ">>";
		setCursorPosition(width / 2 + 16, height / 2 - choice);
		cout << "<<";

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			Sleep(50);
			system("cls");
			return;
		}
		if (GetAsyncKeyState(VK_UP) && choice < 3)
			choice++;
		if (GetAsyncKeyState(VK_DOWN) && choice > 1)
			choice--;
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (choice == 3)
				system("cls");
			else if (choice == 2)
				Play(width, height);
			else if (choice == 1)
				Menu(width, height);
			return;
		}
	}
}

void Loss(short width, short height, short Score)
{
	short choice = 3;
	while (true)
	{
		Sleep(50);
		system("cls");

		setCursorPosition(width / 2 - 20, height / 2 - 8);
		cout << "        Your Score: " << Score;
		setCursorPosition(width / 2 - 20, height / 2 - 5);
		cout << "              Loss                 ";
		setCursorPosition(width / 2 - 20, height / 2 - 4);
		cout << "===================================";
		setCursorPosition(width / 2 - 20, height / 2 - 3);
		cout << "==           Restart             ==";
		setCursorPosition(width / 2 - 20, height / 2 - 2);
		cout << "==          Main menu            ==";
		setCursorPosition(width / 2 - 20, height / 2 - 1);
		cout << "===================================";
		setCursorPosition(width / 2 - 23, height / 2 - choice);
		cout << ">>";
		setCursorPosition(width / 2 + 16, height / 2 - choice);
		cout << "<<";

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			return;
		}
		if (GetAsyncKeyState(VK_UP) && choice < 3)
			choice++;
		if (GetAsyncKeyState(VK_DOWN) && choice > 2)
			choice--;
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (choice == 3)
				Play(width, height);
			else if (choice == 2)
				Menu(width, height);
			return;
		}
	}
}