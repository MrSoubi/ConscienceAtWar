#include "Choice.h"

void Choice::NewChoice(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet, string link) {
	this->text = text;
	this->conditions = conditions;
	this->actions = actions;
	this->timeOffSet = timeOffSet;
	this->link = link;
}

void Choice::Display() {
	cout << text << endl;
}