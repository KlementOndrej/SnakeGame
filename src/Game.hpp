#pragma once
#include <ncurses.h>
#include "Board.hpp"
#include "Stuff.hpp"
#include "Point.hpp"
#include "Empty.hpp"
#include "Snake.hpp"

class Game{
public:
	Game(){
		board = Board();
		game_over = false;
		srand(time(0));

		//testspace
		snake.setDirection(right);

		SnakePiece next = SnakePiece(1, 1);
		board.add(next);
		snake.addPiece(next);

		next = snake.nextPiece();
		board.add(next);
		snake.addPiece(next);

		snake.setDirection(down);

		next = snake.nextPiece();
		board.add(next);
		snake.addPiece(next);

		point = new Point(2, 4);
		board.add(*point);

		//testspace end
	}

	~Game(){
		delete point;
	}

	void input(){
		chtype ipt = board.getInput();
	}

	void update(){
		placePoint();

		//test space
		SnakePiece next = snake.nextPiece();
		if(!(next.getX() == point->getX() && next.getY() == point->getY())){
			board.add(Empty(snake.tail().getX(), snake.tail().getY()));
			snake.removePiece();
		}
		else{
			removePoint();
		}
		board.add(next);
		snake.addPiece(next);
		//test space end
	}

	void redraw(){
		board.refresh();
	}

	bool isOver(){
		return game_over;
	}

	void removePoint(){
			board.add(Empty(point->getX(), point->getY()));
			point = NULL;
	}

	//places point on board if there is none
	void placePoint(){
		if (point == NULL){
			int x, y;
			board.findEmptyXY(x, y);
			point = new Point(x, y);
			board.add(*point);
		}
	}
private:
	Board board;
	Point *point;
	Snake snake;
	bool game_over;
};
