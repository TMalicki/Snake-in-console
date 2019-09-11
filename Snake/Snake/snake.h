#ifndef SNAKE_H

static const int DOWN = 72;
static const int UP = 80;
static const int RIGHT = 77;
static const int LEFT = 75;
static const int ARROW_KEY = 224;


class 
	Snake : public Fruit {
private:
	int head_x, head_y;
	friend class Game;
	int move_x, move_y;
	int moving_Dir;
public:
	Snake(Board&);
	void born();
	void Move();
	// przeciążyć jakoś te funkcje?
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	////////////////////////////////
};

#endif
