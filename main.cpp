#include "World.h"

int main() {

	World w = World();

	w.Init();
	while (w.Step() > 1);
}
