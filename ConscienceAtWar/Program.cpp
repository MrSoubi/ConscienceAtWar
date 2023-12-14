#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <windows.h>
#include "ReadFile.h"
#include "Program.h"

std::string tmpTest = "";

int Program::karma = 0;
std::vector<std::string> Program::inventory = std::vector<std::string>{};

int main(int argc, char* argv[]) {
	//Program::inventory.push_back("");
	std::vector<Scene> scenes = ReadFile::Start(argc, argv);

	scenes[0].Display(scenes);

	return 0;
}