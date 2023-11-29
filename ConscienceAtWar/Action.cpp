#include "Action.h"

Action::Action(string text) {
	this->text = text;
}

bool Action::IsAdditive()
{
	return text[0] == '+';
}

bool Action::IsSubtractive()
{
	return text[0] == '-';
}

string Action::Text()
{
	string textPart;

	for (int i = 1; i < text.size(); i++) {
		textPart.push_back(text[i]);
	}

	return textPart;
}