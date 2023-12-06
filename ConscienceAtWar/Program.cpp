#pragma once

#include <string>
#include <iostream>

#include "ReadFile.h"
#include "Program.h"

std::string tmpTest = "";

std::string dontCloseCmdWindows;

int Program::karma = 0;
std::vector<std::string> Program::inventory = std::vector<std::string>{};

int main(int argc, char* argv[]) {
	std::vector<Scene> scenes = ReadFile::Start(argc, argv);

	scenes[0].Display(scenes);

	std::cin >> dontCloseCmdWindows;
}