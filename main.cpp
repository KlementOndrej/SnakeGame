#include <ncurses.h>
#include "src/Board.hpp"
#include "src/Game.hpp"
#include "src/Menu.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char **argv){
	initscr();
	refresh();

	noecho();
	curs_set(0);

	Menu menu;
	while(menu.isRunning()){
		menu.input();
	}

	endwin();
}
