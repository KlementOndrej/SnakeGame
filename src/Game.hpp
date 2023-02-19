#pragma once
#include <ncurses.h>
#include "Board.hpp"
#include "Stuff.hpp"
#include "Point.hpp"
#include "Snake.hpp"
#include "Scoreboard.hpp"

#define HEIGHT 20
#define WIDTH 50

class Game{
public:
	Game(){
		board = Board(HEIGHT, WIDTH);
		score = 0;
		scoreboard = Scoreboard(WIDTH, board.getStartingX(), board.getStartingY()+HEIGHT, score);
		game_over = false;
		srand(time(0));

		placeSnake();
	}

	~Game(){
		delete point;
	}

	void end(){
		board.clear();
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

	//updates gamestate
	void update(){
		placePoint();

		moveSnake();
	}

	//refreshes scoreboard and gameboard
	void redraw(){
		board.refresh();
		scoreboard.refresh();
	}

	bool isOver(){
		return game_over;
	}

	//reads the next position and interacts with it
	void handleColision(SnakePiece next){
		switch(board.getCharAt(next.getX(), next.getY())){
		//empty space
		case ' ':
			board.display(snake.tail().getX(), snake.tail().getY(), ' ');	//removes tail of the snake
			snake.removePiece();
			break;
		//point
		case 'X':
			removePoint();
			score++;
			scoreboard.updateScore(score);
			break;
		//border or snake piece
		default:
			game_over = true;
			break;
		}
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
		handleColision(next);
		board.add(next);	//snake moves to next position
		snake.addPiece(next);	//adds point on board if there is none
	}

	//removes point from game
	void removePoint(){
			board.display(point->getX(), point->getY(), ' ');
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

	int getScore(){
		return score;
	}
private:
	Board board;
	Scoreboard scoreboard;
	Point *point;
	Snake snake;
	bool game_over;
	unsigned int score;
};
