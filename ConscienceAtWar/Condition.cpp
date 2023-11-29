#include "Condition.h"

Condition::Condition(string name)
{
	this->name = name;
}

bool Condition::IsInInventory() // WIP, check to be made on the first character (!)
{
	bool result = false;

	for (int i = 0; i < inventory.size(); i++) {
		result = result || inventory[i] == name;
	}
}
