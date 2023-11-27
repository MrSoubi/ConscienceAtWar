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

	Choice(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet, string link);

	void Display();
};