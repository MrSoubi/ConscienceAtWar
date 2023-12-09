#pragma once

#include <string>
#include <vector>

#include "Condition.h"
#include "Program.h"
#include "utils.h"

Condition::Condition()
{
	this->name = "Not defined";
}

Condition::Condition(std::string name)
{
	this->name = name;
}

bool Condition::IsInInventory()
{
	bool result = false;

	for (int i = 0; i < Program::inventory.size(); i++) {
		result = result || Program::inventory[i] == Text();
	}

	return result;
}

bool Condition::IsKarmaCondition()
{
	if (name.find("karma") >= 0) {
		return true;
	}
	return false;
}

bool Condition::IsSuperiorKarma() {
	return name[0] != '!';
}

int Condition::GetKarmaValue()
{
	if (IsSuperiorKarma()) {
		std::string d = Text().substr(5);
		return std::stoi(Text().substr(5));
	}
	else return std::stoi(Text().substr(6));
}

bool Condition::IsVerified()
{
	if (IsKarmaCondition()) {
		if (IsSuperiorKarma()) return Program::karma >= GetKarmaValue();
		else return Program::karma <= GetKarmaValue();
	}
	else {
		if (IsNegative()) return !utils::IsInInventory(Text());
		else return utils::IsInInventory(Text());
	}
}

bool Condition::IsNegative()
{
	return name[0] == '!';
}

std::string Condition::Text()
{
	if (IsNegative()) {
		std::string textPart;

		for (int i = 1; i < name.size(); i++) {
			textPart.push_back(name[i]);
		}

		return textPart;
	}
	else {
		return name;
	}
}
