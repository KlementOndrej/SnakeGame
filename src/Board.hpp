#pragma once
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "Stuff.hpp"

#define HEIGHT 20
#define WIDTH 50

class Board{
public:
	Board(){
		int xMax, yMax;
		getmaxyx(stdscr, yMax, xMax);

		game_win = newwin(HEIGHT, WIDTH, (yMax/2)-10, (xMax/2)-25);
		addBorder();
		keypad(game_win, true);
		refresh();
		//srand(time(0));
		game_speed = 1000;
		wtimeout(game_win, game_speed);
	}

	Board(int height, int width){
		int xMax, yMax;
		getmaxyx(stdscr, yMax, xMax);
		starting_x =(xMax/2)-(width/2);
		starting_y = (yMax/2)-(height/2);

		game_win = newwin(height, width, (yMax/2)-(height/2), (xMax/2)-(width/2));
		addBorder();
		keypad(game_win, true);
		refresh();
		//srand(time(0));
		game_speed = 1000;
		wtimeout(game_win, game_speed);
	}

	void addBorder(){
		box(game_win, 0, 0);
	}

	//finds empty coordinate on board
	void findEmptyXY(int& x, int& y){
		int maxX, maxY;
		getmaxyx(game_win, maxY, maxX);
		while(mvwinch(game_win, y = rand() % maxY, x = rand() % maxX) != ' ');
	}

	//sets timeout of board
	void setSpeed(unsigned short int speed){
		game_speed = speed;
		wtimeout(game_win, game_speed);
	}

	void pause(){
		wtimeout(game_win, -1);
	}

	void resume(){
		wtimeout(game_win, game_speed);
	}

	void clear(){
		wclear(game_win);
	}

	void refresh(){
		wrefresh(game_win);
	}

	//displays object from Stuff(for example Point) class on board
	void add(Stuff something){
		display(something.getX(), something.getY(), something.getIcon());
	}

	//displays character on specified location on board
	void display(int x, int y, chtype ch){
		mvwaddch(game_win, y, x, ch);
	}

	//returns character displayed at specified location on board
	chtype getCharAt(int x, int y){
		return mvwinch(game_win, y, x);
	}

	chtype getInput(){
		return wgetch(game_win);
	}

	//returns x coordinate of upper left corner of board
	int getStartingX(){
		return starting_x;
	}

	//returns y coordinate of upper left corner of board
	int getStartingY(){
		return starting_y;
	}
private:
	WINDOW * game_win;
	unsigned short int game_speed;
	int starting_x, starting_y;
};
