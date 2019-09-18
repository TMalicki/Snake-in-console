#include <iostream>
#include "board.h"
#include "fruit.h"
#include "snake.h"
#include "game.h"
#include <Windows.h>

// BUGI : 
// - czasami znak ciala weza (ktory nie nalezy do weza - nie przesuwa sie) pojawia sie gdzies losowo na planszy

/// MODERNIZACJA
/// - poprawic funkcje void Snake::snakeEat() - mozna dodac losowanie bez powtorzen - to przez ta metode
/// - poprawic to co w funkcji bool Game::play() jest
/// - do funkcji ending zaimplementowac funkcje navigate. plus moze jakos tamta metode zrobic bardziej uniwersalna?


int main() 
{	
		Board b1(30, 30);
		//Fruit f1(b1);
		//Game g1(f1);
		//Game g1(b1);
		Game g1(b1);

		g1.settings();
		if (!g1.start()) 
		{
			g1.menu();
		}

		if (g1.start()) 
		{
			g1.draw();	// board game
			g1.born();	// randomly generate snake
			g1.Score();
		}
		while (g1.play())
		{
			g1.move();
			g1.snakeEat();
		}
		return 0;
}

