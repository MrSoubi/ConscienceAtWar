#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Choice.h"


Choice::Choice(std::string text, std::vector<Condition> conditions, std::vector<Action> actions, int timeOffSet, std::string link) {
	this->text = text;
	this->conditions = conditions;
	this->actions = actions;
	this->timeOffSet = timeOffSet;
	this->link = link;
}

void Choice::Display() {
	std::cout << text << std::endl;
}