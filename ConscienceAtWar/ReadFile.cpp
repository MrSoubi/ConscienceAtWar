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
	
	string sceneName;
	int sceneTimer;
	vector<Paragraph> sceneParagraph;

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
		}
	}
}

vector<string> ReadFile::TidyUpScene(string content) {
	vector<string> contentInScene;
	string currentContent;

	for (int i = 0; i < content.length(); i++)
	{
		if (content[i] == *";") {
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
	int cursorHelper = 0;
	string currentTxtregister;

	string paragraphTxt;
	vector <Condition> condition;
	vector <Action> action;
	int timeOffset = 0;

	bool isReading = false;

	for (int i = 0; i < currentTxt.length(); i++)
	{
		if (currentTxt[i] == *"]" && currentTxt[i + 1] == *"]") {
			if (cursorHelper == 0) {
				if(!currentTxtregister.empty()) timeOffset = stof(currentTxtregister);
				currentTxtregister = "";
			}
			else if (cursorHelper == 1) {
				if (!currentTxtregister.empty()) condition = ReadFile::ReadCondition(currentTxtregister);
				currentTxtregister = "";
			}
			else if (cursorHelper == 2) {
				if (!currentTxtregister.empty()) action = ReadFile::ReadAction(currentTxtregister);
				currentTxtregister = "";
			}

			cursorHelper += 1;
			isReading = false;
			i += 1;
		}
		else if (isReading) currentTxtregister += currentTxt[i];
		else if (currentTxt[i] == *"[" && currentTxt[i + 1] == *"[") {
			if (i != 0) {
				paragraphTxt += currentTxtregister;

				Paragraph paragraph = *new Paragraph(paragraphTxt, condition, action, timeOffset);
				allParagraph.push_back(paragraph);
				cursorHelper = 0;
			}
			currentTxtregister = "";
			isReading = true;
			i += 1;
		}
		else currentTxtregister += currentTxt[i];
	}

	paragraphTxt += currentTxtregister;

	Paragraph paragraph = *new Paragraph(paragraphTxt, condition, action, timeOffset);
	allParagraph.push_back(paragraph);

	for (int i = 0; i < allParagraph.size(); i++){
	
		cout << endl << "NEW PARAGRAPH :" << endl;

		cout << allParagraph[i].text << endl;
		cout << allParagraph[i].timeOffSet << endl;

		if(allParagraph[i].conditions.size() > 0) cout << "CONCITION :" << endl;
		for (int i = 0; i < allParagraph[i].conditions.size(); i++)
		{
			cout << allParagraph[i].conditions[i].name << endl;
		}
		if (allParagraph[i].actions.size() > 0) cout << "ACTIONS :" << endl;
		for (int i = 0; i < allParagraph[i].actions.size(); i++)
		{
			cout << allParagraph[i].conditions[i].name << endl;
		}
	}

	return allParagraph;
}

vector<Condition> ReadFile::ReadCondition(string currenttxt) {
	vector<Condition> conditions;
	Condition currentCondition;
	string currentConditionTxt;

	for (int i = 0; i < currenttxt.length(); i++)
	{
		if (currenttxt[i] == *",") {
			currentCondition.name = currentConditionTxt;
			conditions.push_back(currentCondition);
			currentConditionTxt = "";
		}
		else {
			currentConditionTxt += currentConditionTxt[i];
		}
	}

	currentCondition.name = currentConditionTxt;
	conditions.push_back(currentCondition);

	return conditions;
}
vector<Action> ReadFile::ReadAction(string currenttxt) {
	vector<Action> actions;
	Action currentAction;
	string currentActionTxt;

	for (int i = 0; i < currenttxt.length(); i++)
	{
		if (currenttxt[i] == *",") {
			currentAction.text = currentActionTxt;
			actions.push_back(currentAction);
			currentActionTxt = "";
		}
		else {
			currentActionTxt += currentActionTxt[i];
		}
	}

	currentAction.text = currentActionTxt;
	actions.push_back(currentAction);

	return actions;
}

void ReadFile::AddLigne(string ligneToAdd) {
	lignes.push_back(ligneToAdd);
}