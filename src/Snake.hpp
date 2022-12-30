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

	SnakePiece(int x, int y){
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

	void addPiece(SnakePiece new_piece){
		snake.push(new_piece);
	}

	void removePiece(){
		snake.pop();
	}

	SnakePiece tail(){
		return snake.front();
	}

	SnakePiece head(){
		return snake.back();
	}

	SnakePiece nextPiece(){
		int x = head().getX();
		int y = head().getY();

		switch(cur_dir){
		case down:
			y++;
			break;
		case up:
			y--;
			break;
		case right:
			x++;
			break;
		case left:
			x--;
			break;
		}

		return SnakePiece(x, y);
	}

	void setDirection(Direction dir){
		cur_dir = dir;
	}

	Direction getDirection(){
		return cur_dir;
	}
private:
	std::queue<SnakePiece> snake;
	Direction cur_dir;
};
