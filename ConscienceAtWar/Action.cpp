#pragma once

#include <string>
#include "Action.h"
#include "utils.h"
#include "Program.h"

Action::Action()
{
	this->text = "Not defined";
}

Action::Action(std::string text) {
	this->text = text;
}

// Returns true if the first character is '+'
bool Action::IsAdditive()
{
	return text[0] == '+';
}

// Returns true if the first character is '-'
bool Action::IsSubtractive()
{
	return text[0] == '-';
}

// Returns the text without the first character (+ or -)
std::string Action::Text()
{
	std::string textPart;

	for (int i = 1; i < text.size(); i++) {
		textPart.push_back(text[i]);
	}

	return textPart;
}

// Returns true if the text contains the word "karma"
bool Action::IsKarmaAction()
{
	if (text.find("karma") > 0) {
		return true;
	}
	return false;
}

// Returns the absolute karma value of the action
int Action::GetKarmaValue()
{
	return std::stoi(Text().substr(5));
}

void Action::Activate()
{
	if (IsKarmaAction()) {
		if (IsAdditive()) {
			Program::karma += GetKarmaValue();
		}
		else {
			Program::karma -= GetKarmaValue();
		}
	}
	else if (utils::IsInInventory(Text()) && IsSubtractive()){
	}
}

