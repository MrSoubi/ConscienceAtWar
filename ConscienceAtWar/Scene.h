#pragma once

#include <string>
#include <vector>

#include "Paragraph.h"

class Scene
{
public:
	std::string name;
	std::vector<Paragraph> paragraphs;
	std::vector<Choice> choices;
	int timer;

	Scene(std::string name, std::vector<Paragraph> paragraphs, std::vector<Choice> choices, int timer);

	void Display(std::vector<Scene> scene);
};