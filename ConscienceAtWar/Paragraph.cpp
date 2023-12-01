#include "Paragraph.h"

Paragraph::Paragraph(string text, vector<Condition> conditions, vector<Action> actions, int timeOffSet) {
	this->text = text;
	this->conditions = conditions;
	this->actions = actions;
	this->timeOffSet = timeOffSet;
}

void Paragraph::Display(int speed) {
	if (speed > 0) {
		for (char c : text) {
			cout << c << flush;
			this_thread::sleep_for(chrono::milliseconds(speed));
		}
		cout << endl;
	}
	else {
		cout << text << endl;
	}
}