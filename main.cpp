#include "World.h"

int main() {

	World w = World();

	w.Init();

	std::cout << "START SIMULATION" << std::endl;

	while (w.Step());
}
