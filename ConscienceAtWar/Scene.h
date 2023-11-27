#include "Paragraph.h"

class Scene
{
public:
	string name;
	vector<Paragraph> paragraphs;
	vector<Choice> choices;
	int timer;

	Scene(string name, vector<Paragraph> paragraphs, vector<Choice> choices, int timer);

	void Display(vector<Scene> scene);
};