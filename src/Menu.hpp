#pragma once
#include "./MenuWin.hpp"

class Menu{
public:
	Menu(){
		is_running = 1;
		draw();
	}

	//draws menu
	void draw(){
		menuwin = MenuWindow(2);
		Option play = Option(0, "0:(P)lay");
		Option quit = Option(1, "1:(Q)uit");
		menuwin.printOption(play);
		menuwin.printOption(quit);
	}

	bool isRunning(){
		return is_running;
	}

	//handles input in menu
	void input(){
		chtype ipt = menuwin.getInput();

		switch(ipt){
		case 'p':
		case 'P':
		case '0':
			play();
			redraw();
			break;
		case 'q':
		case 'Q':
		case '1':
			is_running = 0;
			break;
		}
	}

	//launches game
	void play(){
		Game game;

		while(!game.isOver()){
			game.input();

			game.update();

			game.redraw();
		}

		game.end();
	}

	void redraw(){
		draw();
		menuwin.refresh();
	}
private:
	MenuWindow menuwin;
	bool is_running;
};
