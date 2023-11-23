#include "ReadFile.h"*
#include "Program.h"

void ReadFile::Read(string path) {
	string content;
	fstream infile;
	infile.open(path, fstream::in);

	while (getline(infile, content))
	{
		Program::AddLigne(content);
	}

	infile.close();
}