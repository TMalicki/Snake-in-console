#include <iostream>
#include <Windows.h>
#include "board.h"

Board::Board(int x, int y)
{
	if (x > 0 && y > 0) {
		global_x_min = 17;
		global_y_min = 3;
		global_x = x + global_x_min;
		global_y = y + global_y_min;	
	}
	else {
		std::cerr << "\nError, board is too small.\n";
		std::exit(0);
	}
}

Board::~Board()
{
	std::cout << "Board zabite\n";
}

void Board::GoTo(short x, short y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Board::Score() {
	GoTo(global_x_min, global_y + 2);
	std::cout << "Punkty:" << score;
}