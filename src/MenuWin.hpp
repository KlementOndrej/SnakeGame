#pragma once
#include <ncurses.h>
#include <string>

using namespace std;

class Option{
public:
	Option(){
		this->index = 0;
		this->name = "";
	}

	Option(int index, string name){
		this->index = index;
		this->name = name;
	}

	string getName(){
		return name;
	}

	int getIndex(){
		return index;
	}

	void setIndex(int i){
		index = i;
	}

private:
	string name;
	int index;
};


//this class handles displaying menu
class MenuWindow{
public:
	MenuWindow(){
		this->number_of_choices = 2;
		int xMax, yMax;
		getmaxyx(stdscr, yMax, xMax);
		menu_win = newwin(4, 10, (yMax/2)-2, (xMax/2)-5);
		box(menu_win, 0, 0);

		keypad(menu_win, true);
		refresh();
	}

	MenuWindow(int number_of_choices){
		this->number_of_choices = number_of_choices;
		int xMax, yMax;
		getmaxyx(stdscr, yMax, xMax);
		menu_win = newwin(number_of_choices+2, 10, (yMax/2)-number_of_choices, (xMax/2)-5);
		box(menu_win, 0, 0);

		keypad(menu_win, true);
		refresh();
	}

	//prints option into the menu window
	void printOption(Option option){
		mvwprintw(menu_win, option.getIndex()+1, 1, option.getName().c_str());
	}

	void refresh(){
		wrefresh(menu_win);
	}

	chtype getInput(){
		return wgetch(menu_win);
	}

private:
	WINDOW * menu_win;
	int number_of_choices;
};

