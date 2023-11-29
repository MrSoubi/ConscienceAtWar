#include "GlobalHeader.h"

class Action
{
public:
	string text;

	Action(string text);
	
	bool IsAdditive();
	bool IsSubtractive();
	string Text();
};