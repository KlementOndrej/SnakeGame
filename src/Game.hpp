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
	}

	~Game(){
		delete point;
	}

	void input(){
		chtype ipt = board.getInput();

		switch(ipt){
		//move up
		case KEY_UP:
		case 'w':
			snake.setDirection(up);
			break;
		//move down
		case KEY_DOWN:
		case 's':
			snake.setDirection(down);
			break;
		//move right
		case KEY_RIGHT:
		case 'd':
			snake.setDirection(right);
			break;
		//move left
		case KEY_LEFT:
		case 'a':
			snake.setDirection(left);
			break;
		//pause
		case 'p':
			board.pause();
			while(board.getInput() != 'p');
			board.resume();
			break;
		}
	}

	void update(){
		placePoint();

		moveSnake();
	}

	void redraw(){
		board.refresh();
	}

	bool isOver(){
		return game_over;
	}

	//places snake and a point in upper left corner
	void placeSnake(){
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

		point = new Point(next.getX(), next.getY()+2);
		board.add(*point);

	}

	void moveSnake(){
		SnakePiece next = snake.nextPiece();
		if(!(next.getX() == point->getX() && next.getY() == point->getY())){	//removes tail piece if next position does not have a point
			board.add(Empty(snake.tail().getX(), snake.tail().getY()));
			snake.removePiece();
		}
		else{
			removePoint();	//snake eats point
		}
		board.add(next);	//snake moves to next position
		snake.addPiece(next);	//adds point on board if there is none
	}

	void removePoint(){
			board.add(Empty(point->getX(), point->getY()));
			delete point;
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
