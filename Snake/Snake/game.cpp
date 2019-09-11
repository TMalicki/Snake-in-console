#include <iostream>
#include "board.h"
#include "fruit.h"
#include "snake.h"
#include "game.h"

Game::Game(Board & x) : Snake(x){
	gameover = 1;
}

void Game::draw() {
		using std::cout;
		using std::endl;

		for (int i = 0; i < global_x; i++) {
			cout << "#";
		}
		cout << endl;
		for (int y = 0; y < global_y; y++) {
			cout << "#";
			for (int x = 1; x < global_x - 1; x++) {
				if ((x == fruit_x) && (y == fruit_y)) cout << "O";
				//else if ((x == head_x) && (y == head_y)) cout << "X";
				else cout << " ";
			}
			cout << "#";
			cout << endl;
		}
		for (int i = 0; i < global_x; i++) {
			cout << "#";
		}
}

bool Game::play() {
	if (head_x == 1 || head_x == global_x || head_y == 0 || head_y == global_y) gameover = 0;
	return gameover;
}

void Game::ending() {
	GoTo(global_x + 10, global_y + 10);
}
