#include "World.h"

void World::Init() {
	Entities.push_back(new StaticObject(1, 2));
	Entities.push_back(new BreakableObject(2, 1, 1));

	Vector2 mob_position = Vector2(0, 0);
	Vector2 mob_direction = Vector2(1, 0.5f);
	Vector2 player_position = Vector2(3, 3);
	Vector2 player_direction = Vector2(-0.5, 0.5);
	Entities.push_back(new Mob(mob_position, mob_direction, 20));
	Entities.push_back(new Player(player_position, player_direction, 10));
}	

int World::Step() {
	int amount_alive = Entities.size();
	for (int i_entity = 0; i_entity < Entities.size(); i_entity++) {
		if (typeid(Entities.at(i_entity)) == typeid(StaticObject)) {
			amount_alive--;
			// DO NOTHING
		} else if (typeid(Entities.at(i_entity)) == typeid(BreakableObject)) {
			BreakableObject* breaka = dynamic_cast<BreakableObject*>(Entities.at(i_entity));
			if (breaka->GetHP() < 0) {
				amount_alive--;
			}
			// DO NOTHING
		}
		else if (typeid(Entities.at(i_entity)) == typeid(Mob)) {
			Mob* mob = dynamic_cast<Mob*>(Entities.at(i_entity));
			Vector2 dir = (*Entities.at(1)->GetPos() - *mob->GetPos()).Normalize(); // L'INDEX BRUT ~~~
			mob->SetDirection(dir);
			mob->SetSpeed(1);
			mob->Move();
			if (mob->GetHP() < 0) {
				amount_alive--;
			}
		}
		else if (typeid(Entities.at(i_entity)) == typeid(Player)) {
			Mob* mob = dynamic_cast<Mob*>(Entities.at(2)); // L'INDEX BRUT ~~~
			Player* player = dynamic_cast<Player*>(Entities.at(i_entity));
			Vector2 dir;
			if (mob->GetHP() < 0) {
				dir = (*Entities.at(1)->GetPos() - *player->GetPos()).Normalize(); // L'INDEX BRUT ~~~
				if ((*Entities.at(1)->GetPos() - *player->GetPos()).Magnitude() <= 1) { // L'INDEX BRUT ~~~
					player->Attack(*mob);
				}
			}
			else {
				dir = (*Entities.at(2)->GetPos() - *player->GetPos()).Normalize(); // L'INDEX BRUT ~~~
			}
			player->SetDirection(dir);
			player->SetSpeed(1);
			if (player->GetHP() < 0) {
				amount_alive--;
			}
		}
	}
	return amount_alive;
}