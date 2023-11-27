#pragma once
#include "GlobalHeader.h"

class Condition
{
public:
	string name;
	bool isInInventory = true;

	void ConditionName(string name);
};