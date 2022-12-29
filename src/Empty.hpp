#pragma once
#include <ncurses.h>
#include "Stuff.hpp"

class Empty: public Stuff{
public:
	Empty(int x, int y){
		this->x = x;
		this->y = y;
		this->icon = ' ';
	}
};
