#include "Choice.h"

class Paragraph
{
public:
	string text;
	vector<Condition> conditions;
	vector<Action> actions;
	int timeOffSet;

	Paragraph(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet);
	void Display();
};