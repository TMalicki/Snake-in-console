#include <iostream>
#include "board.h"
#include "fruit.h"
#include <time.h>
#include <stdlib.h>

Fruit::Fruit(Board& x) : Board(x) {
	srand(time(NULL));
	fruit_x = 0;
	fruit_y = 0;
	pfruit_x = 0;
	pfruit_y = 0;
}

// randomly generate fruit inside board game
void Fruit::generate_rand() {
	fruit_x = (global_x_min + 1) + rand() % (global_x - (global_x_min + 1));
	fruit_y = (global_y_min + 1) + rand() % (global_y - (global_y_min + 1));

	GoTo(fruit_x, fruit_y);
	std::cout << "@";
}