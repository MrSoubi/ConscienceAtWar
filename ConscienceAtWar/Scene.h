#include "Paragraph.h"

class Scene
{
public:
	string name;
	vector<Paragraph> paragraphs;
	vector<Choice> choices;
	int timer;

	void Display();
};