#pragma once
#include <ncurses.h>
#include <queue>
#include "Stuff.hpp"

enum Direction{
	up,
	down,
	left,
	right
};

class SnakePiece: public Stuff{
public:
	SnakePiece(){
		this->x = 0;
		this->y = 0;
		this->icon = '#';
	}

	SnakePiece(int x, int y)[
		this->x = x;
		this->y = y;
		this->icon = '#';
	}
};

class Snake{
public:
	Snake(){
		cur_dir = down;
	}

	addPiece(SnakePiece new_piece){
		snake.push(new_piece);
	}

	removePiece(){
		snake.pop();
	}

	SnakePiece tail(){
		return snake.front();
	}

	SnakePiece head(){
		return snake.back();
	}
private:
	std::queue<SnakePiece> snake;
	Direction cur_dir;
};
