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
		refresh();
		srand(time(0));
	}

	void addBorder(){
		box(game_win, 0, 0);
	}

	void findEmptyXY(int& x, int& y){
		int maxX, maxY;
		getmaxyx(game_win, maxY, maxX);
		while(mvwinch(game_win, y = rand() % maxY, x = rand() % maxX) != ' ');
	}

	void clear(){
		wclear(game_win);
	}

	void refresh(){
		wrefresh(game_win);
	}

	void add(Stuff something){
		display(something.getX(), something.getY(), something.getIcon());
	}

	void display(int x, int y, chtype ch){
		mvwaddch(game_win, y, x, ch);
	}

	chtype getInput(){
		return wgetch(game_win);
	}
private:
	WINDOW * game_win;
};
