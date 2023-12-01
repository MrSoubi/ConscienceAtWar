#include "Choice.h"

Choice::Choice(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet, string link) {
	this->text = text;
	this->conditions = conditions;
	this->actions = actions;
	this->timeOffSet = timeOffSet;
	this->link = link;
}

void Choice::Display(int speed) {
	if (speed > 0) {
		for (char c : text) {
			cout << c << flush;
			this_thread::sleep_for(chrono::milliseconds(speed));
		}
		cout << endl;
	}
	else {
		cout << text << endl;
	}
}