#include "Condition.h"
#include "SceneCreatorTEST.h"

Condition::Condition(string name)
{
	this->name = name;
}

// Gotta use another function in utils, to check for the existance of a string in the inventory, and then check the condition.
bool Condition::IsInInventory() // WIP, check to be made on the first character (!)
{
	bool result = false;

	for (int i = 0; i < SceneCreatorTEST::inventory.size(); i++) {
		result = result || SceneCreatorTEST::inventory[i].name == name;
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

string Condition::Text()
{
	if (IsNegative()) {
		string textPart;

		for (int i = 1; i < name.size(); i++) {
			textPart.push_back(name[i]);
		}

		return textPart;
	}
	else {
		return name;
	}
}
