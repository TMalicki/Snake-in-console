#ifndef BOARD_H

class Board{
private:
	int global_x, global_y, global_x_min, global_y_min;
	friend class Fruit;
	friend class Snake;
	friend class Game;
public:
	Board(int x = 50, int y = 15);
	~Board();
	void GoTo(short x, short y);
	int score = 0;
	void Score();
};

#endif