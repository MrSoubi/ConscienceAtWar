#pragma once

#include <string>
#include <vector>

#include "Choice.h"

class Paragraph
{
public:
	std::string text;
	std::vector<Condition> conditions;
	std::vector<Action> actions;
	bool displayed = false;
	int timeOffSet;

	Paragraph(std::string text, std::vector<Condition> conditions, std::vector<Action> actions, int timeOffSet);

	void ApplyAction();

	bool CanBeDisplayed();

	void Display(int speed);
};