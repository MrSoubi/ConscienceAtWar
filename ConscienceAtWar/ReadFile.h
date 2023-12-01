#pragma once
#include "GlobalHeader.h"
#include "Scene.h"

class ReadFile
{
public:
	static void Start(string tmpTest);

	static void Read(string path);

	static void SetScene(string currentTxt);

	static vector<string> TidyUpScene(string currentTxt);

	static vector<Paragraph> SetParagraph(string currentTxt);

	static vector<Choice> SetChoices(vector<string> currentTxt);

	static vector<Condition> ReadCondition(string currenttxt);
	static vector<Action> ReadAction(string currenttxt);

	static void AddLigne(string ligneToAdd);
};