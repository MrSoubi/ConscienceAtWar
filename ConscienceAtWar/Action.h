#pragma once

#include <string>

class Action
{
public:
	void Activate();







	std::string text;

	Action();
	Action(std::string text);
	
	bool IsAdditive();
	bool IsSubtractive();
	std::string Text();
	bool IsKarmaAction();
	int GetKarmaValue();

};