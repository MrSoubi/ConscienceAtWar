#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <iostream>

#include "Paragraph.h"
#include "utils.h"


Paragraph::Paragraph(std::string text, std::vector<Condition> conditions, std::vector<Action> actions, int timeOffSet) {
	this->text = text;
	this->conditions = conditions;
	this->actions = actions;
	this->timeOffSet = timeOffSet;
}

void Paragraph::ApplyAction() // WARNING ! ALREADY DECLARED IN ACTION
{
	for (int i = 0; i < actions.size(); i++) {
		if (actions[i].IsAdditive() && utils::IsInInventory(actions[i].Text())) {

		}
		else if (actions[i].IsSubtractive() && utils::IsInInventory(actions[i].Text())) {

		}
		else {
			std::cout << "Problem with ApplyAction().";
		}
	}
}

bool Paragraph::CanBeDisplayed()
{
	bool result = true;
	for (int i = 0; i < conditions.size(); i++) {
		result = result && conditions[i].IsInInventory();
	}

	return result;
}

void Paragraph::Display(int speed) {
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