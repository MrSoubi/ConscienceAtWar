#include "utils.h"
#include "SceneCreatorTEST.h"

bool utils::IsInInventory(string text) {
	bool result = false;

	for (int i = 0; i < SceneCreatorTEST::inventory.size(); i++) {
		result = result || SceneCreatorTEST::inventory[i].name == text;
	}

	return result;
}
