#pragma once

#include <string>

class Condition
{
public:
	bool IsVerified();






	std::string name;

	Condition();
	Condition(std::string name);

	bool IsInInventory();

	bool IsNegative();
	std::string Text();
};