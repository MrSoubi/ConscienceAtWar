#pragma once

#include <string>

#include "utils.h"
#include "Program.h"

bool utils::IsInInventory(std::string text) {
	bool result = false;

	for (int i = 0; i < Program::inventory.size(); i++) {
		result = result || Program::inventory[i] == text;
	}

	return result;
}

int utils::GetIndexInInventory(std::string text)
{
	for (int i = 0; i < Program::inventory.size(); i++) {
		if (Program::inventory[i] == text) {
			return i;
		}
	}
	return -1;
}

void utils::RemoveFromInventory(std::string text)
{
	Program::inventory.erase(Program::inventory.begin() + GetIndexInInventory(text));
}

void utils::AddToInventory(std::string text)
{
	Program::inventory.push_back(text);
}

void utils::ResetInventory()
{
	Program::inventory.clear();
}

void utils::ResetKarma()
{
	Program::karma = 0;
}

int utils::Pow(int n, int p)
{
	int result = n;

	for (int i = 1; i <= p; i++) {
		result = result * n;
	}

	return result;
}
