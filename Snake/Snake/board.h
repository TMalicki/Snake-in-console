#ifndef BOARD_H

class Board{
private:
	friend class Fruit;									// fruit class is friend of board class so fruit class can use attributes from board class
	friend class Snake;									// and so on...
	friend class Game;

	int global_x, global_y, global_x_min, global_y_min;	// size of the board
	int score = 0;										// stores score in game

public:
	Board(int x = 50, int y = 20);						// constructor of board class with default values of board size
	~Board();											// destructor of board class
	void GoTo(short x, short y);						// go to exact coord
	void Score();										// method for counting your score
};

#endif