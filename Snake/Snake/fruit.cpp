#include <iostream>
#include "board.h"
#include "fruit.h"
#include <time.h>
#include <stdlib.h>

Fruit::Fruit(Board& x) : Board(x) {
	fruit_x = 0;
	fruit_y = 0;
}

void Fruit::generate_rand() {
	srand(time(NULL));

	fruit_x = 1 + rand() % (global_x-1);
	fruit_y = 1 + rand() % (global_y-1);
}