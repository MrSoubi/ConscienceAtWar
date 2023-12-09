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
	bool IsKarmaCondition();
	bool IsSuperiorKarma();
	int GetKarmaValue();
	bool IsNegative();
	std::string Text();
};