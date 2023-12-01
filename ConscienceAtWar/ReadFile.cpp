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
	int sceneTimer;
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
			sceneParagraph = ReadFile::SetParagraph(currentSceneContent[i]);
			break;
		default:
			choicesTxt.push_back(currentSceneContent[i]);
			break;
		}
	}

	for (int i = 0; i < sceneParagraph.size(); i++)
	{
		cout << endl << sceneParagraph[i].timeOffSet << endl << sceneParagraph[i].text << endl;

		for (int y = 0; y < sceneParagraph[i].conditions.size(); y++)
		{
			cout << sceneParagraph[i].conditions[y].name << endl;
		}
		for (int y = 0; y < sceneParagraph[i].actions.size(); y++)
		{
			cout << sceneParagraph[i].actions[y].text << endl;
		}
	}

	choices = ReadFile::SetChoices(choicesTxt);
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

vector<Paragraph> ReadFile::SetParagraph(string currentTxt) {
	vector<Paragraph> allParagraph;

	string txtRegister;

	int timeOffSet = 0;
	vector<Condition> conditions;
	vector<Action> actions;
	string text;

	int indexHelper = 1;

	bool isReading = false;

	for (int i = 2; i < currentTxt.length(); i++)
	{
		if (currentTxt[i] == '[' && currentTxt[i + 1] == '[') {
			if (isReading) {
				text = txtRegister;

				allParagraph.emplace_back(text, conditions, actions, timeOffSet);

				text = "";
				conditions.clear();
				actions.clear();
				timeOffSet = 0;
				txtRegister = "";
			}

			i += 2;
		}
		else {
			txtRegister += currentTxt[i];
		}

		if (currentTxt[i] == ']' && currentTxt[i + 1] == ']') {
			if (indexHelper == 1) {
				if (txtRegister != "") {
					timeOffSet = stoi(txtRegister);
					txtRegister = "";
				}
			}
			else if (indexHelper == 2){
				if (txtRegister != "") {
					conditions = ReadCondition(txtRegister);
					txtRegister = "";
				}
			}
			else if (indexHelper == 3) {
				if (txtRegister != "") {
					actions = ReadAction(txtRegister);
					txtRegister = "";
				}
				indexHelper = 0;
				isReading = true;
			}

			indexHelper += 1;
			i += 2;
		}
		else {
			txtRegister += currentTxt[i];
		}
	}

	currentTxt.find("");
	int a;
	char* b;
	char* c;
	int d = sscanf(currentTxt.c_str(), "[[%d]][[%s]][[%s]]", &a, b, c);

	text = txtRegister;
	allParagraph.emplace_back(text, conditions, actions, timeOffSet);

	return allParagraph;
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