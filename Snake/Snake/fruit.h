#ifndef FRUIT_H

class Fruit : public Board {
private:
	int fruit_x, fruit_y;
	friend class Snake;
	friend class Game;
public:
	Fruit(Board & x);
	void generate_rand();
};


#endif