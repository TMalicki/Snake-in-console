#ifndef GAME_H

class Game : public Snake{
private:
	bool gameover;
public:
	Game(Board &);
	void draw();
	void ending();
	bool play();
	void settings();
	void menu();
};


#endif