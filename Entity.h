#pragma once

#include "Vector2.h"
#include "AbstractEntity.h"
#include <iostream>

#ifndef __ENTITIES__
#define __ENTITIES__

// Entity =======================================

class Entity{
protected:
	Vector2 Position;

public:
	Entity() {}
	Entity(float, float);

	virtual Vector2* GetPos();
	virtual void SetPos(Vector2&);
};

// Alive =======================================

class Alive {
protected:
	float MaxHP;
	float HP;
public:
	Alive(float);

	void SetHP(float);
	virtual float GetHP();
	virtual float GetMaxHP();
	virtual void TakeDamage(float);
};

// ATTACKER 

class IAttacker {
	virtual void Attack(Alive&) = 0;
};

// STATICOBJECT =======================================

class StaticObject : public Entity {
public:
	StaticObject(float, float);
};

// BREAKABLEOBJECT =================================

class BreakableObject : public Entity, public Alive {
public:
	BreakableObject(float, float, float);
	void TakeDamage(float) override;
};

// MOB =================================

class Mob : public Entity, public Alive, public AMovable {
public:
	Mob(Vector2&, Vector2&, float);
	void TakeDamage(float) override;
	void Move() override;
};

// PLAYER =================================

class Player : public Entity, public Alive, public AMovable, public IAttacker {

public:
	Player(Vector2&, Vector2&, float);
	void TakeDamage(float) override;
	void Move() override;
	void Attack(Alive&) override;
};



#endif // !__ENTITIES__