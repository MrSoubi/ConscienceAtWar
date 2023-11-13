#include "Display.h"

void Display::DisplayScene() {
	using namespace ftxui;

	auto document = 
		border(
			vbox({
				text("Header") | center | flex,
				separator(),
				borderEmpty(
					hbox({
						vtext("l_margin") | borderEmpty,
						borderEmpty(
							vbox({
								text("Paragraphs") | center | flex,
								text("Choices") | center | flex
							})) | flex,
						gaugeUp(1.0f),
						vtext("r_margin") | borderEmpty
					}) | flex),
				separator(),
				text("Footer") | center | flex
			})
	);

	auto screen = Screen(120, 30);
	Render(screen, document);
	screen.Print();
}
