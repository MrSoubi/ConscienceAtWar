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
	int timeOffSet;

	Paragraph(std::string text, std::vector<Condition> conditions, std::vector<Action> actions, int timeOffSet);

	// Displays the paragraph with a delay between each character in milliseconds, and adds 2 endl at the end of the paragraph
	// Use a delay of 0 if you want to display the paragraph directly
	void Display(int delay);

	void ApplyAction();

	bool CanBeDisplayed();
	
	Paragraph(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet);
	void Display(int speed);
};