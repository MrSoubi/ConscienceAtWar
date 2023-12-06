#pragma once

#include <vector>
#include <string>

#include "Scene.h"

class ReadFile
{
public:
	static void Start(std::string tmpTest);

	static void Read(std::string path);

	static void SetScene(std::string currentTxt);

	static std::vector<std::string> TidyUpScene(std::string currentTxt);

	static std::vector<Paragraph> SetParagraphs(std::string currentTxt);
	static Paragraph ReadParagraph(std::string currentTxt);

	static std::vector<Choice> SetChoices(std::vector<std::string> currentTxt);

	static std::vector<Condition> ReadCondition(std::string currenttxt);
	static std::vector<Action> ReadAction(std::string currenttxt);

	static void AddLigne(std::string ligneToAdd);
};