#include <iostream>
#include "board.h"
#include "fruit.h"
#include "snake.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

Snake::Snake(Board& x) : Fruit(x) {
	head_x = 0;
	head_y = 0;
	move_x = 0;
	move_y = 0;
	moving_Dir = 0;
}

void Snake::born() {
	do {
		head_x = 1 + rand() % (global_x - 1);
		head_y = 1 + rand() % (global_y - 1);
	} while ((head_x == fruit_x) && (head_y == fruit_y));

	GoTo(head_x, head_y);
	std::cout << "X";
	move_x = head_x;
	move_y = head_y;
}

void Snake::moveUp(){
	while (!_kbhit() && move_y != global_y+1) {
		move_y++;
		//moving_Dir = move_y;
		GoTo(move_x, move_y);
		std::cout << "X";
		Sleep(200);
	}
}
void Snake::moveDown(){
	while (!_kbhit() && move_y != 0) {
		move_y--;
		//moving_Dir = -move_y;
		GoTo(move_x, move_y);
		std::cout << "X";
		Sleep(200);
	}
}
void Snake::moveRight() {
	while (!_kbhit() && move_x != global_x-1) {
		move_x++;
		//moving_Dir = -move_x;
		GoTo(move_x, move_y);
		std::cout << "X";
		Sleep(100);
	}
}
void Snake::moveLeft() {
	while (!_kbhit() && move_x != 0) {
		move_x--;
		//moving_Dir = move_x;
		GoTo(move_x, move_y);
		std::cout << "X";
		Sleep(100);
	}
}
void Snake::Move()
{
	if (_getch() == ARROW_KEY) {
		switch (_getch()) {
		case UP:
			moveUp();
			break;
		case DOWN:
			moveDown();
			break;
		case LEFT:
			moveLeft();
			break;
		case RIGHT:
			moveRight();
			break;
		}
	}

	//GoTo(move_x, move_y);
	//std::cout << "X";

	/*
	while (!_kbhit()) {
		moving_Dir++;
		GoTo(move_x, move_y);
		std::cout << "X";
		Sleep(500);
	}
	*/
}
