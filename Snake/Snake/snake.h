#ifndef SNAKE_H

static const int DOWN = 72;	// key down button
static const int UP = 80;	// key up button
static const int RIGHT = 77;	// key right button
static const int LEFT = 75;		// key left button
static const int ARROW_KEY = 224;	// arrow key buttons
static const int ENTER = 13;

class 
	Snake : public Fruit {
private:

	int head;
	short dir_x;	//-1 (left or down) / +1 (right or up)
	short dir_y;
	friend class Game;
	int base_length = 3;	// base length of snake on start of the game
	const int length = Board::global_x*Board::global_y;	// max length
	int prev_tailPos[2];			// previous tail position (end of snake)
	int tail;						// tail is sum of base_length and score				
	int time = 500;					//	delay for snake

	struct Body {
		int body_pos[2];	// position of every element of snakes body
		Body* higherEl; // point element nearer head element
	};
	Body* body = new Body[length];  // array for body of snake

public:
	Snake(Board&);
	~Snake();
	void born();
	void move();
	bool snake_collision();
	void snakeEat();
};

#endif