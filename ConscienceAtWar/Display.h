#pragma once
#include <stdio.h>                  // for getchar
#include <ftxui/dom/elements.hpp>   // for filler, text, hbox, vbox
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator

#include "ftxui/dom/node.hpp"      // for Render
#include "ftxui/screen/color.hpp"  // for ftxui

class Display
{
public:
	void DisplayScene();
};

