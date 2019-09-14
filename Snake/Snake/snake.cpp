#include <iostream>
#include "board.h"
#include "fruit.h"
#include "snake.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

Snake::Snake(Board& x) : Fruit(x) {
	head = 0;	// position in snakes body of his head (0 means that it is his first element - of his body)
	dir_x = 0;	// direction change in x axis
	dir_y = 0;	// direction change in y axis
	base_length = 3;	// setting value - starting length of snake		
	prev_tailPos[0] = 0;	// prev tail position coord
	prev_tailPos[1] = 0;	// prev tail position coord
	tail = base_length + score;	// actual in game lenghth of snake ( + score, because he is growing while eating fruits)
	//int inGamebodyLength = base_length + score; // ciał węża w trakcie gry to suma bazowej długośći węża i wyniku (ilości zjedzonych owoców)
}

//-------------------------------
// make a snake with his body
void Snake::born() {

	// randomly put head of snake on board (also checking if it is not inside fruit)
	do {
		body[head].body_pos[0] = (global_x_min + 1) + rand() % ((global_x_min + 1));
		body[head].body_pos[1] = (global_y_min + 1) + rand() % ((global_y_min + 1));
	} while ((body[head].body_pos[0] == fruit_x) && (body[head].body_pos[1] == fruit_y));

	// is it beeing used? check the queue problem algorithm in Stephen Prata c++ book
	for (int i = base_length-1; i > 0; i--) {
		body[i].higherEl = &body[i-1];
	}
	// position of body of snake (for now inside head = he will be expanding during game)
	for (int i = 1; i < base_length; i++) {
		body[i].body_pos[0] = body[head].body_pos[0];
		body[i].body_pos[1] = body[head].body_pos[1];
	}
	// make body of snake in addiction to his coordinate (without head)
	for (int i = base_length -1; i > 0; i--) {
		GoTo(body[i].body_pos[0], body[i].body_pos[1]);
		std::cout << "X";
	}
	// making head of the snake
	GoTo(body[head].body_pos[0], body[head].body_pos[1]);
	std::cout << "+";
}

//---------------------------------------------
// move snake
void Snake::move()
{
	// while keyboard key is hit save his change of position
	// f.e. one pixel up (during that he is not moving left or right
	// so change of position in this side is equal to zero
	while (_kbhit()) {
		if (_getch() == ARROW_KEY) {
			switch (_getch()) {
			case UP:	
				dir_x = 0;
				dir_y = 1;
				time = 200;	// time is different because of different radio of char in x and y check if it is possible to make it equal
				break;
			case DOWN:	
				dir_x = 0;
				dir_y = -1;
				time = 200;
				break;
			case LEFT:
				dir_x = -1;
				dir_y = 0;
				time = 100;
				break;
			case RIGHT:
				dir_x = 1;
				dir_y = 0;
				time = 100;
				break;
			}
		}
	}	
			// saving previous position of tail (last element of snakes body)
			prev_tailPos[0] = body[tail - 1].body_pos[0];
			prev_tailPos[1] = body[tail - 1].body_pos[1];

			// save position of every element of snakes body
			for(int i = tail-1; i > 0; i--){
				body[i].body_pos[0] = body[i - 1].body_pos[0];
				body[i].body_pos[1] = body[i - 1].body_pos[1];
			}

			// save position of snakes head
			body[head].body_pos[0] += dir_x;	//head
			body[head].body_pos[1] += dir_y;	//head

			// start drawing snake (with erasing his last position of tail)
			GoTo(prev_tailPos[0], prev_tailPos[1]);
			std::cout << " ";
			for (int i = (tail - 1); i > 0; i--) 
			{
				GoTo(body[i].body_pos[0], body[i].body_pos[1]);
				std::cout << "X";
			}
			GoTo(body[head].body_pos[0], body[head].body_pos[1]);
			std::cout << "+";

			// growth of snake (in place of previous fruit)
			if (prev_tailPos[0] == pfruit_x && prev_tailPos[1] == pfruit_y) {
				tail = base_length + score;
				body[tail - 1].body_pos[0] = pfruit_x;
				body[tail - 1].body_pos[1] = pfruit_y;
				pfruit_x = 0;
				pfruit_y = 0;
			}
			Sleep(time);
}

bool Snake::snake_collision()
{
	for (int i = head+1; i < tail; i++) {
		if ((body[tail - 2].body_pos[0] != body[tail - 1].body_pos[0]) || (body[tail - 2].body_pos[1] != body[tail - 1].body_pos[1])) {
			if ((body[0].body_pos[0] == body[i].body_pos[0]) && (body[0].body_pos[1] == body[i].body_pos[1])) return true;
		}
	}
	return false;
}

void Snake::snakeEat() 
{
	if ((body[head].body_pos[0] == (fruit_x)) && (body[head].body_pos[1] == (fruit_y))) 
	{	
		pfruit_x = fruit_x;
		pfruit_y = fruit_y;
		score++;
		Board::Score();
		while (body[0].body_pos[0] == fruit_x && body[0].body_pos[1] == fruit_y) Fruit::generate_rand();		
	}
}
