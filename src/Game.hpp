#pragma once
#include <ncurses.h>
#include "Board.hpp"
#include "Stuff.hpp"
#include "Point.hpp"
#include "Empty.hpp"

class Game{
public:
	Game(){
		board = Board();
		game_over = false;
		srand(time(0));
	}

	~Game(){
		delete point;
	}

	void input(){
		chtype ipt = board.getInput();
	}

	void update(){
		placePoint();

	}

	void redraw(){
		board.refresh();
	}

	bool isOver(){
		return game_over;
	}

	void placePoint(){
		int x, y;
		board.findEmptyXY(x, y);

		if (point != NULL) board.add(Empty(point->getX(), point->getY()));

		point = new Point(x, y);
		board.add(*point);
	}
private:
	Board board;
	Point *point;
	bool game_over;
};
