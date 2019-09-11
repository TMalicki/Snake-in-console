#include <iostream>
#include <Windows.h>
#include "board.h"

Board::Board(int x, int y)
{
	if (x > 0 && y > 0) {
		global_x = x;
		global_y = y;
	}
	else {
		std::cerr << "\nError, board is too small.\n";
		std::exit(0);
	}
}

Board::~Board()
{
}

void Board::GoTo(short x, short y) {

	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}