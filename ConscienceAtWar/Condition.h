#pragma once
#include "GlobalHeader.h"
#include "utils.h"

class Condition
{
public:
	string name;

	Condition(string name);

	bool IsInInventory();
	bool IsVerified();
	bool IsNegative();
	string Text();
};