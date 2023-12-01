#include "Program.h"

string tmpTest = "Scene1;9;[[5]][[]][[]]Lorem ipsum dolor sit amet, consectetur adipiscing .\n [[20]] [[gun, ammunition]] [[]] Nam at tincidunt ligula, sit amet ullamcorper erat.Donec mol.\n [[]] [[food]] [[-food, +lol]] Integer no.;0;Answering calmly to the Colonel;BobbyIsDead,blablabla;-BobbyIsDead;Scene 2;4;Answering strongly to the Colonel;Parto;+Parto;Scene 3;";

string dontCloseCmdWindows;

int main(int argc, char* argv[]) {
	ReadFile::Start(tmpTest);

	cin >> dontCloseCmdWindows;
}