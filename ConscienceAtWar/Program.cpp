#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <windows.h>

#include "ReadFile.h"
#include "Program.h"

void SetConsole() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set font size
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, false, &fontInfo);
    fontInfo.dwFontSize.X = 15; // Set width of the font 
    fontInfo.dwFontSize.Y = 20; // Set height of the font
    SetCurrentConsoleFontEx(hConsole, false, &fontInfo);

    HWND console = GetConsoleWindow();

    //add style remove
    LONG style = GetWindowLong(console, GWL_STYLE);
    style &= ~(WS_THICKFRAME | WS_MAXIMIZEBOX);
    SetWindowLong(console, GWL_STYLE, style);


    //remove bar
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD new_size = {
        csbi.srWindow.Right - csbi.srWindow.Left + 1,
        csbi.srWindow.Bottom - csbi.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), new_size);

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Masquer le curseur
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

std::string tmpTest = "";

int Program::karma = 0;
std::vector<std::string> Program::inventory = std::vector<std::string>{};

int main(int argc, char* argv[]) {
    SetConsole();
	//Program::inventory.push_back("");
	std::vector<Scene> scenes = ReadFile::Start(argc, argv);

	scenes[0].Display(scenes);

	return 0;
}