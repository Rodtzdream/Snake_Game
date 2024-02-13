#pragma once
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <chrono>

using namespace std;

extern void setCursorPosition(int, int);
extern void Pause(short, short);
extern void Loss(short, short, short);

extern float target_time;

struct Chain
{
	Chain(short x, short y)
	{
		this->x = x;
		this->y = y;
	}
	short x;
	short y;
};

enum Turn
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Snake
{
public:
	Snake(short width, short height);

	void Update();

private:
	void Control(short&, short&, Turn&);
	void Check(const short, const short);
	void UpdateField();

	vector<Chain> mySnake;
	Turn turn;
	short Score;
	short height;
	short width;
	short goal_x;
	short goal_y;
};