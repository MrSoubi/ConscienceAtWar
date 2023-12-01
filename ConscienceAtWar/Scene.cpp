#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "Scene.h"

Scene::Scene(std::string name, std::vector<Paragraph> paragraphs, std::vector<Choice> choices, int timer) {
	this->name = name;
	this->paragraphs = paragraphs;
	this->choices = choices;
	this->timer = timer;
}

void Scene::Display(std::vector<Scene> scene) {
	std::cout << this->name << std::endl << std::endl;

	for (Paragraph paragraph : paragraphs) {
		paragraph.Display(20);
	}

	std::cout << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	for (Choice choice : choices) {
		choice.Display();
	}
	int playerChoice;
	std::cin >> playerChoice; // temp
	for (int n = 0; n < choices.size(); n++)
	{
		if (playerChoice == n+1) {
			for (int i = 0; i < scene.size(); i++) {
				if (choices[n+1].link == scene[i].name) {
					scene[i].Display(scene);
				}
			}
		}
		else {
			this->Display(scene);
		}
	}
}