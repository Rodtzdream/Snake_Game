#include "Snake.h"

Snake::Snake(short width, short height)
{
	goal_x = rand() % (width - 10) + 5;
	goal_y = rand() % (height - 10) + 5;
	mySnake.push_back(Chain(goal_x, goal_y));

	goal_x = rand() % (width - 2) + 1;
	goal_y = rand() % (height - 2) + 1;

	this->width = width;
	this->height = height;
	turn = static_cast<Turn>(rand() % DOWN);
	this->Score = 0;
}

void Snake::Control(short& temp_x, short& temp_y, Turn& turn)
{
	if (GetAsyncKeyState(VK_LEFT) && turn != RIGHT && turn != LEFT)
	{
		turn = LEFT;
		target_time /= 2;
	}
	if (GetAsyncKeyState(VK_RIGHT) && turn != LEFT && turn != RIGHT)
	{
		turn = RIGHT;
		target_time /= 2;
	}
	if (GetAsyncKeyState(VK_UP) && turn != DOWN && turn != UP)
	{
		turn = UP;
		target_time *= 2;
	}
	if (GetAsyncKeyState(VK_DOWN) && turn != UP && turn != DOWN)
	{
		turn = DOWN;
		target_time *= 2;
	}
	if (GetAsyncKeyState(VK_ESCAPE))
		Pause(width, height);

	if (turn == LEFT)
		temp_x--;
	else if (turn == RIGHT)
		temp_x++;
	else if (turn == UP)
		temp_y--;
	else if (turn == DOWN)
		temp_y++;
}

void Snake::Update()
{
	UpdateField();

	short temp_x = mySnake[0].x;
	short temp_y = mySnake[0].y;

	//clear snake
	for (size_t i = 0; i < mySnake.size(); i++)
	{
		setCursorPosition(mySnake[i].x, mySnake[i].y);
		cout << " ";
	}

	//check keyboard
	Control(temp_x, temp_y, turn);

	//check keyboard
	Check(temp_x, temp_y);

	//move snake
	for (size_t i = 0; i < mySnake.size(); i++)
	{
		swap(temp_x, mySnake[i].x);
		swap(temp_y, mySnake[i].y);
		setCursorPosition(mySnake[i].x, mySnake[i].y);
		cout << "*";
	}
	setCursorPosition(goal_x, goal_y);
	cout << "*";
}

void Snake::UpdateField()
{
	setCursorPosition(1, 0);
	for (size_t i = 1; i < width - 1; i++)
		cout << "_";

	for (size_t i = 1; i < height; i++)
	{
		setCursorPosition(0, i);
		cout << "|";
		setCursorPosition(width - 1, i);
		cout << "|";
	}

	setCursorPosition(1, height - 1);
	for (size_t i = 1; i < width - 1; i++)
		cout << "_";

	setCursorPosition(width - 40, 0);
	cout << " ____________ ";
	setCursorPosition(width - 40, 1);
	cout << "|            |";
	setCursorPosition(width - 40, 2);
	cout << "| Score: " << setw(3) << Score << " |";
	setCursorPosition(width - 40, 3);
	cout << "|____________|";
}

void Snake::Check(const short temp_x, const short temp_y)
{
	for (size_t i = 0; i < mySnake.size(); i++)
	{
		if (temp_x == mySnake[i].x && temp_y == mySnake[i].y && temp_x != goal_x && temp_y != goal_y)
			exit(0);
	}

	//generate new goal
	if (temp_x == goal_x && temp_y == goal_y)
	{
		setCursorPosition(goal_x, goal_y);
		cout << " ";
		mySnake.push_back(Chain(temp_x, temp_y));
		goal_x = rand() % (width - 2) + 1;
		goal_y = rand() % (height - 2) + 1;
		Score += 10;
	}

	//border check
	if (temp_x == 0 || temp_x == width - 1)
		Loss(width, height, this->Score);
	else if (temp_y == 0 || temp_y == height - 1)
		Loss(width, height, this->Score);
	else if (temp_x == width - 41 && temp_y >= 1 && temp_y <= 2)
		Loss(width, height, this->Score);
	else if (temp_x == width - 27 && temp_y >= 1 && temp_y <= 2)
		Loss(width, height, this->Score);
	else if (temp_x >= width - 41 && temp_x <= width - 27 && temp_y == 3)
		Loss(width, height, this->Score);
}