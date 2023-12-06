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

bool Action::IsAdditive()
{
	return text[0] == '+';
}

bool Action::IsSubtractive()
{
	return text[0] == '-';
}

std::string Action::Text()
{
	std::string textPart;

	for (int i = 1; i < text.size(); i++) {
		textPart.push_back(text[i]);
	}

	return textPart;
}

bool Action::IsKarmaAction()
{
	if (text.find("karma") > 0) {
		return true;
	}
	return false;
}

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

