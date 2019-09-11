#ifndef BOARD_H

class Board{
private:
	int global_x, global_y;
	friend class Fruit;
	friend class Snake;
	friend class Game;
public:
	Board(int x = 50, int y = 20);
	~Board();
	void GoTo(short x, short y);
};

#endif