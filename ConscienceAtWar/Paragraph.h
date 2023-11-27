#include "Choice.h"

class Paragraph
{
public:
	string text;
	vector<Condition> conditions;
	vector<Action> actions;
	int timeOffSet;

	void NewParagraph(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet);
	void Display();
};