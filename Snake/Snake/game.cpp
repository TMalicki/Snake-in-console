#include <iostream>
#include "board.h"
#include "fruit.h"
#include "snake.h"
#include "game.h"
#include <conio.h>
#include <Windows.h>

using std::cout;
using std::endl;

Game::Game(Board & x) : Snake(x){
	gameover = 0;
}


Game::~Game() {
	std::cout << "Game zabite\n";
}


void Game::draw() {

		for (int i = global_x_min; i <= global_x; i++) {
			GoTo(i, global_y_min);
			cout << "#";
		}
		cout << endl;

		for (int y = global_y_min+1; y < global_y; y++) {
			GoTo(global_x_min, y);
			cout << "#";
			GoTo(global_x, y);
			cout << "#";
		}

		for (int i = global_x_min; i <= global_x; i++) {
			GoTo(i, global_y);
			cout << "#";
		}
		if(gameover == 1) Fruit::generate_rand();	
}

bool Game::play() {

	if (body[0].body_pos[0] == global_x_min || body[0].body_pos[0] == global_x || body[0].body_pos[1] == global_y_min || 
		body[0].body_pos[1] == global_y || Snake::snake_collision()) 
	{

		const char* names[4];
		names[0] = "GAMEOVER";
		names[1] = "PLAY AGAIN?";
		names[2] = "YES";
		names[3] = "NO!";
		int** wsk;
		wsk = draw_center(names, 4);
		int choose;
		choose = navigate(4, wsk);

		switch (choose) {
		case 2: {
			system("cls");
		
			// jak tu wywołać destruktor obiektu poprzedniego?
			// o ile mozna wgl, no i jak tu zrobic nowy obiekt
			// typu Game? Z lista inicjalizacyjna? No i zeby 
			// skopiowano do niego z uzyciem konstruktora
			// kopiujacego co trzeba? (czyli obiekt poprzedni?) 
			// w sumie chyba nic nie trzeba kopiowac?

			dir_x = 0; dir_y = 0;
			score = 0;
			tail = base_length + score;
			
			// by nie trzeba bylo robic tego pomiedzy
			// generalnie czy jest jakis sposob na 
			// wywolanie inteligentne tego co jest w 
			// konstruktorach ... albo wyrzucic pewne rzeczy
			// z konstruktorow i przebudowac co nie co by byl
			// latwiejszy dostep 
			/////////////////////////////////////////////

			draw();	// board game
			born();	// randomly generate snake
			Score();
			gameover = 1;
		}
				break;
		case 3: {
			system("cls");
			gameover = 0;
			//delete[] wsk;
		}
				break;
		}
	}
	return gameover;
}

int** Game::draw_center(const char* names[], int size) {
	int* names_length = new int[size];
	int** center = new int* [size];
	
	//int* center_x = new int[size];
	//int* center_y = new int[size];
	
	for (int i = 0; i < size; i++) {
		center[i] = new int[2];
		names_length[i] = strlen(names[i]);
		center[i][0] = (((global_x - global_x_min) / 2) + global_x_min - ((names_length[i] / 2) - 1));
		center[i][1] = (((global_y - global_y_min) / 2) + (global_y_min - (size/2)) - 1) + i;
	}

	for (int i = 0; i < size; i++) {
		GoTo(center[i][0], center[i][1]);
		std::cout << names[i];
	}
	delete[] names_length;
	/////////////////////////////
	// return center_x, center_y
	/////////////////////////////
	return center;
}

int Game::navigate(int size, int** center) {
	int pos = 2;
	int pos_pop = pos;
	short offset = 3;

	int max = global_x; 
	for (int i = 2; i < size; i++) {
		if (center[i][0] < max) max = center[i][0];
	}

	GoTo(max - offset, center[pos][1]);
	std::cout << "->";

		while (_getch() != ENTER)
		{
			switch (_getch())
			{
			case UP:
			{
				pos_pop = pos;
				pos++;
				if (pos > (size - 1))
				{
					pos = size - 1;
				}
			}
			break;
			case DOWN:
			{
				pos_pop = pos;
				pos--;
				if (pos < 2) {
					pos = 2;
				}
			}
			break;
			}
			GoTo(max - offset, center[pos_pop][1]);
			std::cout << "  ";
			GoTo(max - offset,center[pos][1]);
			std::cout << "->";
		}
		//cout << "ZATWIERDZONO\n\n";

		return pos;
}
// add here arrow and choosing with arrow keys and enter button
int Game::interactive_op() {

	const int size = 6;
	const char* names[size];

	names[0] = "MENU";
	names[1] = "----";
	names[2] = "PLAY";
	names[3] = "DEMO";
	names[4] = "SETTINGS";
	names[5] = "QUIT";

	int** wsk = draw_center(names, size);
	return navigate(size, wsk);
}

int Game::change_speed() {

	int speed = 100;

	system("cls");
	draw();
	const char* names[5];

	names[0] = "SPEEED";
	names[1] = "++++++++++----------"; // 20 levelss

	int** wsk = draw_center(names, 2);
	int point = wsk[1][0]+9;
	int prev_key = RIGHT; // zeby dzialalo (bo wskaznik sie w lewo zle przesuwal inaczej przy pierwszym wcisnieciu przycisku)

	GoTo(wsk[1][0] + 4, wsk[1][1] + 1);
	std::cout << "JUST AVERAGE";
	GoTo(wsk[1][0] + 5, wsk[1][1] + 2);
	std::cout << "Speed: " << 150 - speed;
	GoTo(wsk[1][0], wsk[1][1] + 3);
	std::cout << "ACCEPT (press ENTER)";

	while (_getch() != ENTER)
	{
		switch (_getch())
		{
		case LEFT:
		{
			if (prev_key == RIGHT) point++;
			if (speed < 150) {
				GoTo(--point, wsk[1][1]);
				std::cout << "-";
				speed += 5;
				prev_key = LEFT;
			}
		}
		break;
		case RIGHT:
		{
			if (prev_key == LEFT) point--;
			if (speed > 50) {
				GoTo(++point, wsk[1][1]);
				std::cout << "+";
				prev_key = RIGHT;
				speed -= 5;
			}
		}
		break;
		}

		GoTo(wsk[1][0], wsk[1][1] + 2);
		std::cout << "                    ";
		GoTo(wsk[1][0] + 5, wsk[1][1] + 2);
		std::cout << "Speed: " << 150 - speed;
		GoTo(wsk[1][0], wsk[1][1] + 1);

		if (speed < 70) {
			std::cout << "                    ";
			GoTo(wsk[1][0] + 5, wsk[1][1] + 1);
			std::cout << "BOOMBASTIC!";	
		}
		else if (speed > 130) {
			std::cout << "                    ";
			GoTo(wsk[1][0] + 5, wsk[1][1] + 1);
			std::cout << "SLOOOOWLY!";
		}
		else {
			std::cout << "                    ";
			GoTo(wsk[1][0] + 4, wsk[1][1] + 1);
			std::cout << "JUST AVERAGE";
		}
	}

	system("cls");
	return speed;
}

int Game::change_length() {

	int length = 10;

	system("cls");
	draw();
	const char* names[5];

	names[0] = "LENGTH";
	names[1] = "++++++++++----------"; // 20 levelss

	int** wsk = draw_center(names, 2);
	int point = wsk[1][0] + 9;
	int prev_key = RIGHT; // zeby dzialalo (bo wskaznik sie w lewo zle przesuwal inaczej przy pierwszym wcisnieciu przycisku)

	GoTo(wsk[1][0] + 5, wsk[1][1] + 1);
	std::cout << "Length: " << length;
	GoTo(wsk[1][0], wsk[1][1] + 2);
	std::cout << "ACCEPT (press ENTER)";


	while (_getch() != ENTER)
	{
		switch (_getch())
		{
		case LEFT:
		{
			if (prev_key == RIGHT) point++;
			if (length > 0) {
				GoTo(--point, wsk[1][1]);
				std::cout << "-";
				length -= 1;
				prev_key = LEFT;
			}
		}
		break;
		case RIGHT:
		{
			if (prev_key == LEFT) point--;
			if (length < 20) {
				GoTo(++point, wsk[1][1]);
				std::cout << "+";
				prev_key = RIGHT;
				length += 1;
			}
		}
		break;
		}

		GoTo(wsk[1][0], wsk[1][1] + 1);
		std::cout << "                    ";
		GoTo(wsk[1][0] + 5, wsk[1][1] + 1);
		std::cout << "Length: " << length;
	}

	system("cls");
	return length;
}

void Game::option() {
	const int size = 5;
	const char* names[size];

	names[0] = "MENU";
	names[1] = "----";
	names[2] = "LENGTH";
	names[3] = "SPEED";
	names[4] = "RETURN";

	int** wsk = draw_center(names, size);
	int choose = navigate(size, wsk);

	switch (choose)
	{
	case 2: {
		base_length = change_length();
		tail = base_length + score;
		option();
	}
			break;
	case 3: {
		time = change_speed();
		option();
	}
			break;
	case 4: {
		system("cls");
		menu();
	}
			break;
	}
}
void Game::menu() {
	int choose = 0;

	draw();
	choose = interactive_op();

	switch (choose) {
		case 2: {
			system("cls");
			gameover = 1;
		}
			break;
		case 3: {
			demo();
		}
			break;
		case 4:
			system("cls");
			option();
			break;
		case 5: {
			system("cls");
			gameover = 0;
			break;
		}
			break;
		default: {

		}
	}
}

void Game::demo() {
//	while (g1.play()) {
//		g1.move();
//		g1.snakeEat();
//	}
	
}

bool Game::start() {
	return gameover;
}

void Game::settings() {

	// size of window console
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions
		MoveWindow(console, 500, 80, 500, 650, TRUE); // 800 width, 600 height

	// invisible cursor (that normally blinks)
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO ci;
		ci.dwSize = 100;
		ci.bVisible = FALSE;
		SetConsoleCursorInfo(output, &ci);

	// set new font for console window. Normally font ratio is not equal (height and width are not equal)
	// so we set font with ratio 8x8 (so now it is equal in both sizes) - 8x8 is only equal ratio
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
		lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
		GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
		lpConsoleCurrentFontEx->dwFontSize.X = 18;
		lpConsoleCurrentFontEx->dwFontSize.Y = 18;
		SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}