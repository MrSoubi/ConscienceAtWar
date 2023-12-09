#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Paragraph.h"
#include "Choice.h"

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