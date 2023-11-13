#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

#include "main.h"

int main(void) {
    GraphicalAPITest();
}

void GraphicalAPITest() {
    using namespace ftxui;

    // Define the document
    Element document =
        hbox({
          text("left") | border,
          text("middle") | border | flex,
          text("right") | border,
            });

    auto screen = Screen::Create(
        Dimension::Full(),       // Width
        Dimension::Fit(document) // Height
    );
    Render(screen, document);
    screen.Print();
}