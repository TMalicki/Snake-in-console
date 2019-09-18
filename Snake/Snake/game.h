#ifndef GAME_H

class Game : public Snake{
private:
	bool gameover;
public:
	Game(Board &);
	~Game();
	void draw();
	bool play();
	void settings();
	void menu();
	bool start();
	int interactive_op();
	void option();
	int** draw_center(const char* names[], int size);
	int navigate(int size, int** center);
	int change_length();
	int change_speed();
	void demo();
/*
	static const int ARROW_KEY = 224;		// first value after push arrow key button
	static const int KEY_UP = 72;			// second value after push arrow key button (up)
	static const int KEY_DOWN = 80;			// second value after push arrow key button (down)
	static const int KEY_LEFT = 75;
	static const int KEY_RIGHT = 77;
	static const int ENTER = 13;			// first and only value after push enter button
	*/
	};


#endif