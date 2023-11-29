#pragma once
#include "GlobalHeader.h"

class Condition
{
public:
	string name;

	Condition(string name);

	bool IsInInventory();
};