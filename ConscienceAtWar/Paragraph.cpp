#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <iostream>

#include "Paragraph.h"
#include "utils.h"
#include <windows.h>


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

void Paragraph::Display(int lengh, int speed) {
    int counter = 0;

    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    std::cout << "   ";
    std::cout << (char)186 << " " << "-> ";
    for (char c : text) {
        if (counter <= lengh - 18) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            counter++;
        }
        else {
			std::cout << "     ";
			std::cout << (char)186 << std::endl << "   " << (char)186 << "    " << c << std::flush;
            counter = 0;
        }
    }
    std::cout << std::endl << std::endl;
}