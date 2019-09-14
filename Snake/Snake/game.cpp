#include <iostream>
#include "board.h"
#include "fruit.h"
#include "snake.h"
#include "game.h"
#include <conio.h>
#include <Windows.h>

Game::Game(Board & x) : Snake(x){
	gameover = 1;
}

void Game::draw() {
		using std::cout;
		using std::endl;

		for (int i = global_x_min; i <= global_x; i++) {
			GoTo(i, global_y_min);
			cout << "#";
		}
		cout << endl;

		for (int y = global_y_min+1; y < global_y; y++) {
			GoTo(global_x_min, y);
			cout << "#";
			GoTo(global_x, y);
			cout << "#";
		}

		for (int i = global_x_min; i <= global_x; i++) {
			GoTo(i, global_y);
			cout << "#";
		}
		Fruit::generate_rand();
}

bool Game::play() {
	if (body[0].body_pos[0] == global_x_min || body[0].body_pos[0] == global_x || body[0].body_pos[1] == global_y_min || body[0].body_pos[1] == global_y) gameover = 0;
	else if (Snake::snake_collision()) gameover = 0;
	
	return gameover;
}

void Game::ending() {
	GoTo(global_x/2, global_y/2);
	std::cout << "GAMEOVER\n";
	_getch();
}

void Game::menu() {
	int choose = 0;

		GoTo((global_x - global_x_min) / 2, (global_y - global_y_min) / 2);
		std::cout << "MENU:";
		GoTo((global_x - global_x_min) / 2, ((global_y - global_y_min) / 2) + 1);
		std::cout << "Play";
		GoTo((global_x - global_x_min) / 2, ((global_y - global_y_min) / 2) + 2);
		std::cout << "Settings";

	choose = _getch();
	switch (choose) {
		case 1: {
			system("cls");
			gameover = 1;
		}
			break;
		case 2: 
			break;
		default: {

		}
	}
}

void Game::settings() {

	// size of window console
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions
		MoveWindow(console, r.left, r.top, 800, 600, TRUE); // 800 width, 600 height

	// invisible cursor (that normally blinks)
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO ci;
		ci.dwSize = 100;
		ci.bVisible = FALSE;
		SetConsoleCursorInfo(output, &ci);

	// set new font for console window. Normally font ratio is not equal (height and width are not equal)
	// so we set font with ratio 8x8 (so now it is equal in both sizes) - 8x8 is only equal ratio
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
		lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
		GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
		lpConsoleCurrentFontEx->dwFontSize.X = 18;
		lpConsoleCurrentFontEx->dwFontSize.Y = 18;
		SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}