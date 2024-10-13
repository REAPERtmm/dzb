#include "World.h"

void World::Init() {
	Entities.push_back(new StaticObject(1, 2));
	Entities.push_back(new BreakableObject(20, 0, 11));

	Vector2* mob_position = new Vector2(10, 0);
	Vector2* mob_direction = new Vector2();
	Vector2* player_position = new Vector2(0, 0);
	Vector2* player_direction = new Vector2();
	Entities.push_back(new Mob(*mob_position, *mob_direction, 20));
	Entities.push_back(new Player(*player_position, *player_direction, 10));
}	


Mob* World::GetMob() {
	for (auto entity = Entities.begin(); entity < Entities.end(); entity++) {
		if (typeid(*(*entity)) == typeid(Mob)) {
			Mob* mob = dynamic_cast<Mob*>(*entity);
			if (mob->GetHP() > 0) {
				return mob; 
			}
		}
	}
	return NULL;
}

BreakableObject* World::GetBreakable() {
	for (auto entity = Entities.begin(); entity < Entities.end(); entity++) {
		if (typeid(*(*entity)) == typeid(BreakableObject)) {
			BreakableObject* breakable = dynamic_cast<BreakableObject*>(*entity);
			if (breakable->GetHP() > 0) return breakable;
		}
	}
	return NULL;
}

Player* World::GetPlayer() {
	for (auto entity = Entities.begin(); entity < Entities.end(); entity++) {
		if (typeid(*(*entity)) == typeid(Player)) {
			Player* player = dynamic_cast<Player*>(*entity);
			if (player->GetHP() > 0) return player;
		}
	}
	return NULL;
}

int World::Step() {
	/*
	Mob:Il doit se deplacer vers le BreakableObject.
	Player: Si le Mob est en Vie: Il doit se déplacer vers un Mob et l’attaquer si il est à moins de 1 de distance du joueur. Si le Mob est mort, il doit se déplacer vers un BreakableObject et l’attaquer si il est à moins de 1 de distance du joueur.
	Si tous les Mobs et BreakableObjects sont morts, écrire “Simulation Finished”
	*/

	Player* player = GetPlayer();
	Mob* mob = GetMob();
	BreakableObject* breakable = GetBreakable();
	
	std::cout << "\n\nAT THE START OF THIS FRAME : " << std::endl;
	if (player != NULL) std::cout << "PLAYER ALIVE WITH " << player->GetHP() << " HP AT " << player->GetPos()->toString() << std::endl;
	else std::cout << "PLAYER IS DEAD" << std::endl;
	
	if (mob != NULL) std::cout << "MOB ALIVE WITH " << mob->GetHP() << " HP AT " << mob->GetPos()->toString() << std::endl;
	else std::cout << "MOB IS DEAD" << std::endl;	
	
	if (breakable != NULL) std::cout << "BREAKABLE ALIVE WITH " << breakable->GetHP() << " HP AT " << breakable->GetPos()->toString() << std::endl;
	else std::cout << "BREAKABLE IS DEAD" << std::endl;

	std::cout << "\nAPPEND THIS FRAME : " << std::endl;
	if (mob == NULL) {
		if (breakable == NULL) {
			std::cout << "SIMULATION FINISHED" << std::endl;
			return 0;
		}
		else {
			Vector2 distance_p_b = (*breakable->GetPos() - *player->GetPos());
			Vector2 dir = distance_p_b.Normalize();
			std::cout << "Distance Player - Breakable : " << distance_p_b.Magnitude() << std::endl;

			player->SetDirection(dir);
			player->SetSpeed(1);
			player->Move();

			if (distance_p_b.Magnitude() < 1) {
				player->Attack(*breakable);
			}
		}
	}
	else {
		Vector2 distance_m_b = (*breakable->GetPos() - *mob->GetPos());
		Vector2 dir1 = distance_m_b.Normalize();
		std::cout << "Distance mob - Breakable : " << distance_m_b.Magnitude() << std::endl;
		mob->SetDirection(dir1);
		mob->SetSpeed(1);
		mob->Move();

		Vector2 distance_p_m = (*mob->GetPos() - *player->GetPos());
		Vector2 dir2 = distance_p_m.Normalize();
		std::cout << "Distance mob - player : " << distance_p_m.Magnitude() << std::endl;
		player->SetDirection(dir2);
		player->SetSpeed(1);
		player->Move();

		if (distance_p_m.Magnitude() < 1) {
			player->Attack(*mob);
		}
	}

	return 1;
}