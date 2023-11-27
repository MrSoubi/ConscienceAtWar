#include "Condition.h"
#include "Action.h"

class Choice
{
public:
	string text;
	vector<Condition> conditions;
	vector<Action> actions;
	int timeOffSet;
	string link;

	void NewChoice(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet, string link);

	void Display();
};