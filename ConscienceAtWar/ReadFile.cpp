#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Action.h"
#include "Condition.h"

#include "ReadFile.h"

std::vector<std::string> lignes;

std::vector<Scene> scenes;

int posToContinueInContent;

std::vector<Scene> ReadFile::Start(int argc, char* argv[]) {
	ReadFile::Read(argv[1]);

	for (int i = 1; i < lignes.size(); i++)
	{
		std::string currentSceneTxt = lignes[i];
		if(currentSceneTxt.length() > 50) scenes.push_back(ReadFile::SetScene(currentSceneTxt));
	}

	return scenes;
}

void ReadFile::Read(std::string path) {
	std::string content;

	std::fstream infile;
	infile.open(path, std::fstream::in);

	while (getline(infile, content)) ReadFile::AddLigne(content);

	infile.close();
}

Scene ReadFile::SetScene(std::string currentTxt) {
	std::vector<std::string> currentSceneContent = ReadFile::TidyUpScene(currentTxt);
	std::vector<std::string> choicesTxt;
	
	std::string sceneName;
	float sceneTimer = 0;
	std::vector<Paragraph> sceneParagraph;
	std::vector<Choice> choices;

	for (int i = 0; i < currentSceneContent.size(); i++)
	{
		switch (i) {
		case 0:
			sceneName = currentSceneContent[i];
			break;
		case 1:
			if (currentSceneContent[i] == "") sceneTimer = 0;
			else sceneTimer = stof(currentSceneContent[i]);
			break;
		case 2:
			sceneParagraph = ReadFile::SetParagraphs(currentSceneContent[i]);
			break;
		default:
			choicesTxt.push_back(currentSceneContent[i]);
			break;
		}
	}
	choices = ReadFile::SetChoices(choicesTxt);

	return *new Scene(sceneName, sceneParagraph, choices, sceneTimer);
}

std::vector<std::string> ReadFile::TidyUpScene(std::string content) {
	std::vector<std::string> contentInScene;
	std::string currentContent;

	for (int i = 0; i < content.length(); i++)
	{
		if (content[i] == ';') {
			contentInScene.push_back(currentContent);
			currentContent = "";
		}
		else {
			currentContent += content[i];
		}
	}

	return contentInScene;
}

std::vector<Paragraph> ReadFile::SetParagraphs(std::string currentTxt) {
	std::vector<Paragraph> allParagraph;
	std::string currentParagraphTxt;
	bool paragraphsToRead = true;

	int indexStart = 0;
	int indexA = 0;
	int indexEnd;
	while (paragraphsToRead) {

		// Recherche de l'index venant juste après le 6e ']'
		for (int i = 3; i > 0; i -= 1) {
			indexA = currentTxt.find("]]", indexA) + 2;
		}

		if (currentTxt.find("[[", indexA) != std::string::npos){
			indexEnd = currentTxt.find("[[", indexA);
			currentParagraphTxt = currentTxt.substr(indexStart, indexEnd - indexStart);
			allParagraph.push_back(ReadFile::ReadParagraph(currentParagraphTxt));
			indexStart = indexEnd;
			indexA = indexEnd;
		}else{
			indexEnd = currentTxt.length() - 1;
			currentParagraphTxt = currentTxt.substr(indexStart, indexEnd);
			allParagraph.push_back(ReadFile::ReadParagraph(currentParagraphTxt));
			paragraphsToRead = false;
		}
	}
	return allParagraph;
}

Paragraph ReadFile::ReadParagraph(std::string currentTxt) {
	std::string text;
	std::vector<Condition> conditions;
	std::vector<Action> actions;
	int timeOffSet = 0;

	std::string tmpTxt;

	int indexStart = 0;
	int indexEnd;

	for (int i = 3; i > 0; i -= 1) {
		indexStart = currentTxt.find("[[", indexStart) + 2;
		indexEnd = currentTxt.find("]]", indexStart);
		tmpTxt = currentTxt.substr(indexStart, indexEnd - indexStart);

		switch (i)
		{
		case 0:
			if (tmpTxt == "") timeOffSet = 0;
			else timeOffSet = stoi(tmpTxt);
			break;
		case 1:
			actions = ReadFile::ReadAction(tmpTxt);
			break;
		case 2:
			conditions = ReadFile::ReadCondition(tmpTxt);
			break;
		}
	}

	indexStart = currentTxt.find("]]", indexEnd) + 2;
	indexEnd = currentTxt.length() - 1;
	tmpTxt = currentTxt.substr(indexStart, indexEnd - indexStart);
	text = tmpTxt;

	return *new Paragraph(text, conditions, actions, timeOffSet);
}

std::vector<Choice> ReadFile::SetChoices(std::vector<std::string> currentTxt) {
	std::vector<Choice> choices;
	
	int choicesCount = (int)currentTxt.size() / 5;

	int timeOffset;
	std::string text;
	std::vector<Condition> conditions;
	std::vector<Action> actions;
	std::string link;

	for (int i = 0; i < choicesCount; i++)
	{
		int tmp = i * 5;

		if (currentTxt[tmp] == "") timeOffset = 0;
		else timeOffset = stoi(currentTxt[tmp]);
		text = currentTxt[tmp + 1];
		conditions = ReadFile::ReadCondition(currentTxt[tmp + 2]);
		actions = ReadFile::ReadAction(currentTxt[tmp + 3]);
		link = currentTxt[tmp + 4];

		choices.emplace_back(text, conditions, actions, timeOffset, link);
	}

	return choices;
}

std::vector<Condition> ReadFile::ReadCondition(std::string currenttxt) {
	std::vector<Condition> conditions;
	Condition currentCondition;
	std::string currentContent;

	for (int i = 0; i < currenttxt.length(); i++)
	{
		if (currenttxt[i] == ',') {
			currentCondition.name = currentContent;
			conditions.push_back(currentCondition);
			currentContent = "";
		}
		else {
			currentContent += currenttxt[i];
		}
	}

	currentCondition.name = currentContent;
	conditions.push_back(currentCondition);
	currentContent = "";

	return conditions;
}
std::vector<Action> ReadFile::ReadAction(std::string currenttxt) {
	std::vector<Action> actions;
	Action currentAction;
	std::string currentContent;

	for (int i = 0; i < currenttxt.length(); i++)
	{
		if (currenttxt[i] == ',') {
			currentAction.text = currentContent;
			actions.push_back(currentAction);
			currentContent = "";
		}
		else {
			currentContent += currenttxt[i];
		}
	}
	currentAction.text = currentContent;
	actions.push_back(currentAction);
	currentContent = "";

	return actions;
}

void ReadFile::AddLigne(std::string ligneToAdd) {
	lignes.push_back(ligneToAdd);
}