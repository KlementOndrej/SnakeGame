#pragma once
#include <ncurses.h>
#include "Stuff.hpp"

class Point: public Stuff{
public:
	Point(int x, int y){
		this->x = x;
		this->y = y;
		this->icon = 'X';
	}
};
