#include "Choice.h"

Choice::Choice(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet, string link) {
	this->text = text;
	this->conditions = conditions;
	this->actions = actions;
	this->timeOffSet = timeOffSet;
	this->link = link;
}

void Choice::Display() {
	cout << text << endl;
}