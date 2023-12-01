#pragma once

#include <string>
#include <vector>

#include "Condition.h"
#include "ProgramTestManu.h"
#include "utils.h"

Condition::Condition(std::string name)
{
	this->name = name;
}

bool Condition::IsInInventory()
{
	bool result = false;

	for (int i = 0; i < ProgramTestManu::inventory.size(); i++) {
		result = result || ProgramTestManu::inventory[i] == Text();
	}

	return result;
}

bool Condition::IsVerified()
{
	if (IsNegative()) {
		if (utils::IsInInventory(Text())) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (utils::IsInInventory(Text())) {
			return true;
		}
		else {
			return false;
		}
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
