#include "Scene.h"

int main(){
	vector<Action> actions;
	vector<Condition> conditions;

	vector<Scene> allScenes;

	//scene 1

	vector<Paragraph> scene1paragraphs;
	vector<Choice> scene1choices;
	
	scene1paragraphs.emplace_back("Bonjour et bienvenue !", vector<Condition>{}, vector<Action>{}, 0);

	scene1choices.emplace_back("Bonjour et merci !", vector<Condition>{}, vector<Action>{}, 0, "Scene1");
	scene1choices.emplace_back("...", vector<Condition>{}, vector<Action>{}, 0, "Scene2");
	scene1choices.emplace_back("J'y arrive pas", vector<Condition>{}, vector<Action>{}, 3, "Scene2");

	allScenes.emplace_back("Scene1", scene1paragraphs, scene1choices, 5);

	//scene 2

	vector<Paragraph> scene2paragraphs;
	vector<Choice> scene2choices;

	scene2paragraphs.emplace_back("je sais pas quoi dire", vector<Condition>{}, vector<Action>{}, 0);
	scene2paragraphs.emplace_back("blablabla", vector<Condition>{}, vector<Action>{}, 0);

	scene2choices.emplace_back("j'suis d'accord", vector<Condition>{}, vector<Action>{}, 0, "Scene2");
	scene2choices.emplace_back("il fait beau aujourd'hui", vector<Condition>{}, vector<Action>{}, 0, "Scene1");
	scene2choices.emplace_back("graou", vector<Condition>{}, vector<Action>{}, 0, "Scene1");

	allScenes.emplace_back("Scene2", scene2paragraphs, scene2choices, 5);

	//scene display 

	allScenes[0].Display(allScenes);
};