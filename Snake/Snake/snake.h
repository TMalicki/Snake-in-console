#ifndef SNAKE_H

static const int DOWN = 72;
static const int UP = 80;
static const int RIGHT = 77;
static const int LEFT = 75;
static const int ARROW_KEY = 224;


class 
	Snake : public Fruit {
private:
	int head;
	short dir_x; //-1 (left or down) / +1 (right or up)
	short dir_y;
	friend class Game;
	int base_length;
	const int length = Board::global_x*Board::global_y;
	struct Body {
		int body_pos[2];
		Body* higherEl; // point element nearer head element
	};
	Body* body = new Body[length];
	int prev_tailPos[2];
	int score = 0;
	int tail;;
	int time = 0;
public:
	Snake(Board&);
	void born();
	void move();
	bool snake_collision();
	void snakeEat();
};

#endif
