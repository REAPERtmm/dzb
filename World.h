#pragma once

#include <iostream>
#include <vector>
#include "Entity.h"

#ifndef __WORLD__
#define __WORLD__

class World {

private:
	Mob* GetMob();
	BreakableObject* GetBreakable();
	Player* GetPlayer();
public:
	std::vector<Entity *> Entities;

	World() {};

	void Init();
	int Step();


};

#endif // !__WORLD__

