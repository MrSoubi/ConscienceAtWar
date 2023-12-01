#pragma once

#include <string>

class utils
{
public:
	// string text MUST be only the text part, without the '+', '-' or '!'
	static bool IsInInventory(std::string text);

	static int GetIndexInInventory(std::string text);
	static void RemoveFromInventory(std::string text);
	static void AddToInventory(std::string text);

	static int Pow(int n, int p);
};

