#pragma once
#include "GlobalHeader.h"
#include "Scene.h"

class ReadFile
{
public:
	static void Start(string tmpTest);

	static void Read(string path);

	static void SetScene(string currentTxt);

	static string FindSceneText(int posInContent, string content);
	static int GetNumber(int posInContent, string content);

	static void AddLigne(string ligneToAdd);
};