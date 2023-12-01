#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include "Choice.h"

Choice::Choice(std::string text, std::vector<Condition> conditions, std::vector<Action> actions, int timeOffSet, std::string link) {
	this->text = text;
	this->conditions = conditions;
	this->actions = actions;
	this->timeOffSet = timeOffSet;
	this->link = link;
}

void Choice::Display(int speed) {
	if (speed > 0) {
		for (char c : text) {
			std::cout << c << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(speed));
		}
		std::cout << std::endl;
	}
	else {
		std::cout << text << std::endl;
	}
}