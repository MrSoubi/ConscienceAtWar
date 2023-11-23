#include "GlobalHeader.h"
#include "Program.h"
#include "Scene.h"
#include "ReadFile.h"

vector<string> lignes;

vector<Scene> scenes;

int posToContinueInContent;

string dontCloseCmdWindows;

int main(int argc, char* argv[]) {
	ReadFile::Read(argv[1]);

	for (int i = 1; i < lignes.size(); i++)
	{
		Program::SetScene(lignes[i]);
	}

	cin >> dontCloseCmdWindows;
}

void Program::SetScene(string currentTxt) {
	Scene currentScene = *new Scene;

	currentScene.name = Program::FindSceneText(0, currentTxt);
	cout << posToContinueInContent;
	currentScene.timer = Program::GetNumber(posToContinueInContent, currentTxt);

	scenes.push_back(currentScene);
}


string Program::FindSceneText(int posInContent, string content) {
	string txtRegister;
	
	for (int i = posInContent; i < content.length(); i++)
	{
		if (content[i] == *";") {
			posToContinueInContent = i++;
			return txtRegister;
		}
		else txtRegister += content[i];
	}
}

int Program::GetNumber(int posInContent, string content) {
	string txtRegister;

	for (int i = posInContent; i < content.length(); i++)
	{
		if (content[i] == *";") {
			posToContinueInContent = i++;

			int numberGet = stof(txtRegister);
			return numberGet;
		}
		else txtRegister += content[i];
	}
}


void Program::AddLigne(string ligneToAdd) {
	lignes.push_back(ligneToAdd);
}