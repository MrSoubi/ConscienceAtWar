#pragma once
#include "GlobalHeader.h"

class Program {
public:
	static void SetScene(string currentTxt);

	static string FindSceneText(int posInContent, string content);
	static int GetNumber(int posInContent, string content);

	static void AddLigne(string ligneToAdd);
};