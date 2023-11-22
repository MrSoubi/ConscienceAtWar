#include "Paragraph.h"

Paragraph::Paragraph(string text, vector<Condition*> conditions, vector<Action*> actions, int timeOffSet) {
	this->text = text;
	this->conditions = conditions;
	this->actions = actions;
	this->timeOffSet = timeOffSet;
}