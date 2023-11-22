#include "Scene.h"

void Scene::Display() {
	cout << this->name << endl << endl;

	for (Paragraph paragraph : paragraphs) {
		paragraph.Display();
	}

	cout << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << endl;

	for (Choice choice : choices) {
		choice.Display();
	}
}