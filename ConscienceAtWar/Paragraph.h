#include "Choice.h"

class Paragraph
{
public:
	int timeOffSet;
	vector<Condition> conditions;
	vector<Action> actions;
	string text;

	Paragraph(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet);
	void Display();
};