#include "Paragraph.h"

Paragraph::Paragraph(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet) {
	this->text = text;
	this->conditions = conditions;
	this->actions = actions;
	this->timeOffSet = timeOffSet;
}

void Paragraph::Display(int delay) {
	for (int i = 0; i < text.length(); i++) {
		cout << text[i];
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
	cout << endl << endl;
}

void Paragraph::ApplyAction()
{
	for (int i = 0; i < actions.size(); i++) {

	}
}

bool Paragraph::CanBeDisplayed()
{
	bool result = true;
	for (int i = 0; i < conditions.size(); i++) {
		result = result && conditions[i].IsInInventory();
	}

	return result;
}