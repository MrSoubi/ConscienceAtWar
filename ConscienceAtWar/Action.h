#pragma once

#include <string>

class Action
{
public:
	std::string text;

	Action(std::string text);
	
	bool IsAdditive();
	bool IsSubtractive();
	std::string Text();
	bool IsKarmaAction();
	int GetKarmaValue();
	void Activate();
};