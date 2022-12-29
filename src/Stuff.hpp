#pragma once

class Stuff{
public:
	Stuff(){
		x = y = 0;
		icon = ' ';
	}

	Stuff(int x, int y, chtype icon){
		this->x = x;
		this->y = y;
		this->icon = icon;
	}

	int getX(){
		return x;
	}

	int getY(){
		return y;
	}

	chtype getIcon(){
		return icon;
	}
protected:
	int x, y;
	chtype icon;
};
