#include "Scene.h"
Scene::Scene(string name, vector<Paragraph> paragraphs, vector<Choice> choices, int timer) {
	this->name = name;
	this->paragraphs = paragraphs;
	this->choices = choices;
	this->timer = timer;
}

void Scene::Display(vector<Scene> scene) {
	cout << this->name << endl << endl;

	for (Paragraph paragraph : paragraphs) {
		paragraph.Display();
	}

	cout << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << endl;

	for (Choice choice : choices) {
		choice.Display();
	}
	int playerChoice;
	cin >> playerChoice; // temp
	for (int n = 0; n < choices.size(); n++)
	{
		if (playerChoice == n+1) {
			for (int i = 0; i < scene.size(); i++) {
				if (choices[n+1].link == scene[i].name) {
					scene[i].Display(scene);
				}
			}
		}
	}
}