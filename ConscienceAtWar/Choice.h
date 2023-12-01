#pragma once

#include <vector>

#include "Condition.h"
#include "Action.h"

class Choice
{
public:
	std::string text;
	std::vector<Condition> conditions;
	std::vector<Action> actions;
	int timeOffSet;
	std::string link;

	Choice(std::string text, std::vector<Condition> conditions, std::vector<Action> actions, int timeOffSet, std::string link);

	void Display();
};