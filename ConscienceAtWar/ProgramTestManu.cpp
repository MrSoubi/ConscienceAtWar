#pragma once

#include <string>
#include <vector>

#include "ProgramTestManu.h"

int ProgramTestManu::karma = 0;
std::vector<std::string> ProgramTestManu::inventory = std::vector<std::string>{};

int main(){
	//Actions / Conditions TEST

	std::vector<Scene> allScenes;
	std::vector<Action> actions;
	std::vector<Condition> conditions;


	Action act_SniperAlive = Action("SniperAlive");
	Action act_SniperDead = Action("SniperDead");

	Condition cond_SniperAlive = Condition("SniperAlive");
	Condition cond_SniperDead = Condition("sniperDead");

	//scene 1

	std::vector<Paragraph> scene1paragraphs;
	std::vector<Choice> scene1choices;
	
	scene1paragraphs.emplace_back("Bonjour et bienvenue !", std::vector<Condition>{}, std::vector<Action>{}, 0);

	scene1choices.emplace_back("Bonjour et merci !", std::vector<Condition>{}, std::vector<Action>{}, 0, "Scene1");
	scene1choices.emplace_back("...", std::vector<Condition>{}, std::vector<Action>{}, 0, "Scene2");
	scene1choices.emplace_back("J'y arrive pas", std::vector<Condition>{}, std::vector<Action>{}, 3, "Scene2");

	allScenes.emplace_back("Scene1", scene1paragraphs, scene1choices, 5);

	//scene 2

	std::vector<Paragraph> scene2paragraphs;
	std::vector<Choice> scene2choices;

	scene2paragraphs.emplace_back("je sais pas quoi dire", std::vector<Condition>{}, std::vector<Action>{}, 0);
	scene2paragraphs.emplace_back("blablabla", std::vector<Condition>{}, std::vector<Action>{}, 0);

	scene2choices.emplace_back("j'suis d'accord", std::vector<Condition>{}, std::vector<Action>{}, 0, "Scene2");
	scene2choices.emplace_back("il fait beau aujourd'hui", std::vector<Condition>{}, std::vector<Action>{}, 0, "Scene1");
	scene2choices.emplace_back("graou", std::vector<Condition>{}, std::vector<Action>{}, 0, "Scene1");

	Paragraph scene1paragraph1 = Paragraph("Bonjour et bienvenue !Bonjour et bienvenue !Bonjour et bienvenue !", conditions, actions, 0);
	Paragraph scene1paragraph2 = Paragraph("il vous reste 5s", conditions, actions, 5);
	allScenes.emplace_back("Scene2", scene2paragraphs, scene2choices, 5);

	//scene display 

	allScenes[0].Display(allScenes);
};