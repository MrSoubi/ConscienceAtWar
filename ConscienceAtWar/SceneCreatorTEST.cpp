#include "Scene.h"

int main(){
	//Actions / Conditions TEST

	vector<Scene> allScenes;
	vector<Action> actions;
	vector<Condition> conditions;

	Action act_SniperAlive;
	Action act_SniperDead;

	Condition cond_SniperDead;
	Condition cond_SniperAlive;

	act_SniperAlive.ActionName("SniperAlive");
	act_SniperDead.ActionName("SniperDead");

	cond_SniperAlive.ConditionName("SniperAlive");
	cond_SniperDead.ConditionName("sniperDead");

	actions.push_back(act_SniperAlive);
	actions.push_back(act_SniperDead);

	conditions.push_back(cond_SniperAlive);
	conditions.push_back(cond_SniperDead);

	//Scene TEST

	vector<Paragraph> scene1paragraphs; // Paragraph scene 1
	vector<Choice> scene1choices; // choices scene 1

	Scene scene1 = Scene("Scene1", scene1paragraphs, scene1choices, 15);

	Paragraph scene1paragraph1 = Paragraph("Bonjour et bienvenue !", conditions, actions, 0);
	Paragraph scene1paragraph2 = Paragraph("il vous reste 5s", conditions, actions, 5);

	Choice scene1choice1 = Choice("Bonjour et merci !", conditions, actions, 0, "Scene1");
	Choice scene1choice2 = Choice("...", conditions, actions, 0, "Scene1");
	Choice scene1choice3 = Choice("j'y arrive pas", conditions, actions, 5, "Scene1");

	scene1paragraphs.push_back(scene1paragraph1);
	scene1paragraphs.push_back(scene1paragraph2);

	scene1choices.push_back(scene1choice1);
	scene1choices.push_back(scene1choice2);
	scene1choices.push_back(scene1choice3);

	scene1.Scene::Scene("Scene1", scene1paragraphs, scene1choices, 0);

	allScenes.push_back(scene1);

	scene1.Display(allScenes);
};