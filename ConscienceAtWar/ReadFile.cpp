#define _CRT_SECURE_NO_WARNINGS
#include "ReadFile.h"

vector<string> lignes;

vector<Scene> scenes;

int posToContinueInContent;

void ReadFile::Start(string tmpTest) {
	ReadFile::Read(tmpTest);

	/*for (int i = 1; i < lignes.size(); i++)
	{
		ReadFile::SetScene(lignes[i]);
	}*/

	ReadFile::SetScene(tmpTest);
}

void ReadFile::Read(string path) {
	string content;
	fstream infile;
	infile.open(path, fstream::in);

	while (getline(infile, content))
	{
		ReadFile::AddLigne(content);
	}

	infile.close();
}

void ReadFile::SetScene(string currentTxt) {
	vector<string> currentSceneContent = ReadFile::TidyUpScene(currentTxt);
	vector<string> choicesTxt;
	
	string sceneName;
	float sceneTimer = 0;
	vector<Paragraph> sceneParagraph;
	vector<Choice> choices;

	for (int i = 0; i < currentSceneContent.size(); i++)
	{
		switch (i) {
		case 0:
			sceneName = currentSceneContent[i];
			break;
		case 1:
			sceneTimer = stof(currentSceneContent[i]);
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

	cout << "Scene infos" << endl;
	cout << sceneName << endl
		<< sceneTimer << endl << endl;

	cout << "Scene Paragraph" << endl;

	for (int i = 0; i < sceneParagraph.size(); i++)
	{
		cout << sceneParagraph[i].text << endl << sceneParagraph[i].timeOffSet << endl;

		cout << "paragraph condition" << endl;

		for (int j = 0; j < sceneParagraph[i].conditions.size(); j++)
		{
			cout << sceneParagraph[i].conditions[j].name << endl;
		}
		cout << "paragraph actions" << endl;

		for (int j = 0; j < sceneParagraph[i].actions.size(); j++)
		{
			cout << sceneParagraph[i].actions[j].text << endl;
		}
	}

	cout << "Scene choices" << endl;

	for (int i = 0; i < choices.size(); i++)
	{
		cout << choices[i].text << endl << choices[i].timeOffSet << endl << choices[i].link << endl;

		cout << "choice condition" << endl;

		for (int j = 0; j < choices[i].conditions.size(); j++)
		{
			cout << choices[i].conditions[j].name << endl;
		}
		cout << "choice action" << endl;

		for (int j = 0; j < choices[i].actions.size(); j++)
		{
			cout << choices[i].actions[j].text << endl;
		}
	}
}

vector<string> ReadFile::TidyUpScene(string content) {
	vector<string> contentInScene;
	string currentContent;

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

vector<Paragraph> ReadFile::SetParagraphs(string currentTxt) {
	vector<Paragraph> allParagraph;
	string currentParagraphTxt;
	bool paragraphsToRead = true;

	int indexStart = 0;
	int indexA = 0;
	int indexEnd;
	while (paragraphsToRead) {

		// Recherche de l'index venant juste après le 6e ']'
		for (int i = 3; i > 0; i -= 1) {
			indexA = currentTxt.find("]]", indexA) + 2;
		}

		if (currentTxt.find("[[", indexA) != string::npos){
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

Paragraph ReadFile::ReadParagraph(string currentTxt) {	
	string text;
	vector<Condition> conditions;
	vector<Action> actions;
	int timeOffSet = 0;

	string tmpTxt;

	int indexStart = 0;
	int indexEnd;

	for (int i = 3; i > 0; i -= 1) {
		indexStart = currentTxt.find("[[", indexStart) + 2;
		indexEnd = currentTxt.find("]]", indexStart);
		tmpTxt = currentTxt.substr(indexStart, indexEnd - indexStart);

		switch (i)
		{
		case 0:
			timeOffSet = stoi(tmpTxt);
			break;
		case 1:
			conditions = ReadFile::ReadCondition(tmpTxt);
			break;
		case 2:
			actions = ReadFile::ReadAction(tmpTxt);
			break;
		}
	}

	indexStart = currentTxt.find("]]", indexEnd) + 2;
	indexEnd = currentTxt.length() - 1;
	tmpTxt = currentTxt.substr(indexStart, indexEnd - indexStart);
	text = tmpTxt;

	return *new Paragraph(text, conditions, actions, timeOffSet);
}

vector<Choice> ReadFile::SetChoices(vector<string> currentTxt) {
	vector<Choice> choices;
	
	int choicesCount = (int)currentTxt.size() / 5;

	int timeOffset;
	string text;
	vector<Condition> conditions;
	vector<Action> actions;
	string link;

	for (int i = 0; i < choicesCount; i++)
	{
		int tmp = i * 5;

		timeOffset = stoi(currentTxt[tmp]);
		text = currentTxt[tmp + 1];
		conditions = ReadFile::ReadCondition(currentTxt[tmp + 2]);
		actions = ReadFile::ReadAction(currentTxt[tmp + 3]);
		link = currentTxt[tmp + 4];

		choices.emplace_back(text, conditions, actions, timeOffset, link);
	}

	return choices;
}

vector<Condition> ReadFile::ReadCondition(string currenttxt) {
	vector<Condition> conditions;
	Condition currentCondition;
	string currentContent;

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
vector<Action> ReadFile::ReadAction(string currenttxt) {
	vector<Action> actions;
	Action currentAction;
	string currentContent;

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

void ReadFile::AddLigne(string ligneToAdd) {
	lignes.push_back(ligneToAdd);
}