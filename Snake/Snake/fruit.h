#ifndef FRUIT_H

class Fruit : public Board {
private:
	int fruit_x, fruit_y;			// fruit coord
	int pfruit_x, pfruit_y;			// previous fruit coord
	friend class Snake;				// snake class is friend of fruit class so snake class can use attributes from fruit class
	friend class Game;				// and so on...
public:
	Fruit(Board & x);				// fruit class constructor (has to initialise board class constructor, so reference to board class is used)
	~Fruit();
	void generate_rand();			// randomly generate fruit on the board
};


#endif