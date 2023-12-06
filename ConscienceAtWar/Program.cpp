#pragma once

#include <string>
#include <iostream>

#include "ReadFile.h"
#include "Program.h"

std::string tmpTest = "Scene1;9;[[5]][[gun,ammunition]][[+Surgian,-Program]]Lorem ipsum dolor sit amet, consectetur adipiscing.[[20]][[Clock]][[]] Nam at tincidunt ligula, sit amet ullamcorper erat.Donec mol.[[]][[food]][[-food,+lol]] Integer no.;0;Answering calmly to the Colonel;BobbyIsDead,blablabla;-BobbyIsDead;Scene 2;4;Answering strongly to the Colonel;Parto;+Parto;Scene 3;";

std::string dontCloseCmdWindows;

int Program::karma = 0;
std::vector<std::string> Program::inventory = std::vector<std::string>{};

int main(int argc, char* argv[]) {
	ReadFile::Start(tmpTest);

	std::cin >> dontCloseCmdWindows;
}