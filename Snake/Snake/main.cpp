#include <iostream>
#include "board.h"
#include "fruit.h"
#include "snake.h"
#include "game.h"
#include <Windows.h>

int main() {

	Board b1(50, 20);
	//b1.draw();
	Fruit f1(b1);
	Snake s1(f1);

	Game g1(f1);
	Game g2(b1);
	Game g3(s1);

	g1.generate_rand(); // randomly generate fruit
	g1.draw();	// board game
	g1.born();	// randomly generate snake
	while (g1.play()) {
		g1.Move();
	}
	//snake


	g1.ending();
	return 0;
}