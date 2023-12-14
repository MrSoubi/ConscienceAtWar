#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>

#include "Choice.h"

Choice::Choice(std::string text, std::vector<Condition> conditions, std::vector<Action> actions, int timeOffSet, std::string link) {
	this->text = text;
	this->conditions = conditions;
	this->actions = actions;
	this->timeOffSet = timeOffSet;
	this->link = link;
}

void Choice::Display(int lengh, int speed, int number) {
    int counter = 0;

    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    for (int i = 0; i <= 20; i++) {
        std::cout << " ";
    }
    std::cout << (char)186 << " " << number <<". ";
    for (char c : text) {
        if (counter <= lengh - 18) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            counter++;
        }
        else {
            std::cout << "     ";
            std::cout << (char)186 << std::endl << "   " << (char)186 << "    ";
            counter = 0;
        }
    }
    std::cout << std::endl << std::endl;
}