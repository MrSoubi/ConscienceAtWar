#include "GlobalHeader.h"
#include "ReadFile.h"*
#include "Program.h"
#include "Scene.h"

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

	cout << scenes[0].name << endl;
	cout << scenes[0].timer << endl;
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
	Scene currentScene = *new Scene;

	currentScene.name = ReadFile::FindSceneText(0, currentTxt);
	currentScene.timer = ReadFile::GetNumber(posToContinueInContent, currentTxt);

	scenes.push_back(currentScene);
}

string ReadFile::FindSceneText(int posInContent, string content) {
	string txtRegister = "";

	for (int i = posInContent; i < content.length(); i++)
	{
		if (content[i] == *";") {
			posToContinueInContent = i ++;
			return txtRegister;
		}
		else txtRegister += content[i];
	}
}

int ReadFile::GetNumber(int posInContent, string content) {
	string txtRegister = "";
	int numberGet = 0;

	for (int i = posInContent; i < content.length(); i++)
	{
		if (content[i] == *";") {
			posToContinueInContent = i++;

			if (txtRegister == "") {
				numberGet = 0;
				cout << "No text here" << endl;
			}
			else numberGet = stof(txtRegister);
			return numberGet;
		}
		else {
			txtRegister += content[i];
		}
	}
}


void ReadFile::AddLigne(string ligneToAdd) {
	lignes.push_back(ligneToAdd);
}