#include "Program.h"

string tmpTest = "Scene1;9;[[]] [[]] [[]]Lorem ipsum dolor sit amet, consectetur adipiscing .\n [[20]] [[gun, ammunition]] [[]] Nam at tincidunt ligula, sit amet ullamcorper erat.Donec mol.\n [[]] [[food]] [[-food, +lol]] Integer no.;0;Answering calmly to the Colonel;;;Scene 2;0;Answering strongly to the Colonel;;;Scene 3;;;;;";

string dontCloseCmdWindows;

int main(int argc, char* argv[]) {
	ReadFile::Start(tmpTest);

	cin >> dontCloseCmdWindows;
}