#include <ncurses.h>
#include "src/Board.hpp"
#include "src/Game.hpp"

int main(int argc, char **argv){
	initscr();
	refresh();

	noecho();
	curs_set(0);

	Game game;

	//main loop
	while(!game.isOver()){
		game.input();

		game.update();

		game.redraw();
	}

	endwin();
}
