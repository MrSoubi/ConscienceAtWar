#pragma once

#include <string>

class Condition
{
public:
	std::string name;

	Condition();
	Condition(std::string name);

	bool IsInInventory();
	bool IsVerified();
	bool IsNegative();
	std::string Text();
};