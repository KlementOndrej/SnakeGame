#pragma once

class Scoreboard{
public:
	Scoreboard(){}

	Scoreboard(int width, int x, int y, unsigned int initial_score){
		score_win = newwin(1, width, y, x);
		clear();
		mvwprintw(score_win, 0, 0, "Score:");
		updateScore(initial_score);
		refresh();
	}

	void updateScore(unsigned int score){
		mvwprintw(score_win, 0, score_win->_maxx - 10, "%11lu", score);
	}

	void clear(){
		wclear(score_win);
	}

	void refresh(){
		wrefresh(score_win);
	}
private:
	WINDOW * score_win;
};
