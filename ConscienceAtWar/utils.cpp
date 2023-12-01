#pragma once

#include <string>

#include "utils.h"
#include "ProgramTestManu.h"

bool utils::IsInInventory(std::string text) {
	bool result = false;

	for (int i = 0; i < ProgramTestManu::inventory.size(); i++) {
		result = result || ProgramTestManu::inventory[i] == text;
	}

	return result;
}

int utils::GetIndexInInventory(std::string text)
{
	for (int i = 0; i < ProgramTestManu::inventory.size(); i++) {
		if (ProgramTestManu::inventory[i] == text) {
			return i;
		}
	}
	return -1;
}

void utils::RemoveFromInventory(std::string text)
{
	ProgramTestManu::inventory.erase(ProgramTestManu::inventory.begin() + GetIndexInInventory(text));
}

void utils::AddToInventory(std::string text)
{
	ProgramTestManu::inventory.push_back(text);
}

int utils::Pow(int n, int p)
{
	int result = n;

	for (int i = 1; i <= p; i++) {
		result = result * n;
	}

	return result;
}
