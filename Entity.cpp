#include "Entity.h"

// Entity =======================================

Entity::Entity(float _x, float _y) {
	Position = Vector2(_x, _y);
}

Vector2* Entity::GetPos() {
	return &Position;
}

void Entity::SetPos(Vector2& _pos) {
	Position.x = _pos.x;
	Position.y = _pos.y;
}

// ALIVE ========================================

Alive::Alive(float _hp) : MaxHP(_hp), HP(_hp) {

}

void Alive::SetHP(float _hp) {
	HP = _hp;
}

float Alive::GetHP() {
	return HP;
}

float Alive::GetMaxHP() {
	return MaxHP;
}

void Alive::TakeDamage(float _dmg) {
	HP -= _dmg;
}

// STATICOBJECT =================================

StaticObject::StaticObject(float _x, float _y) {
	Entity(_x, _y);
	std::cout << "Static Object just created at x = " << _x << " and y = " << _y << std::endl;
}

// BREAKABLEOBJECT =================================

BreakableObject::BreakableObject(float _x, float _y, float _hp) : Alive(_hp) {
	Entity(_x, _y);
	std::cout << "Breakable Object just created at x = " << _x << " and y = " << _y << " with " << _hp << " hp" << std::endl;
}

void BreakableObject::TakeDamage(float _dmg) {
	Alive::TakeDamage(_dmg);
	if (GetHP() < GetMaxHP()) {
		std::cout << "Breakable Object just broke" << std::endl;
	}
}

// MOB =================================

Mob::Mob(Vector2& _pos, Vector2& _dir, float _hp) : Alive(_hp), AMovable(_dir, 0) {
	Entity(_pos.x, _pos.y);
	std::cout << "Mob just created at x = " << _pos.x << " and y = " << _pos.y << " with " << _hp << " life with direction x = " << _dir.x << " and y = " << _dir.y << std::endl;
}

void Mob::TakeDamage(float _dmg) {
	Alive::TakeDamage(_dmg);
	std::cout << "Mob just die" << std::endl;
}

void Mob::Move() {
	Position += Direction * Speed;
	std::cout << "Mob move to x = " << Position.x << " and y = " << Position.y << std::endl;
}

// PLAYER =================================

Player::Player(Vector2& _pos, Vector2& _dir, float _hp) : Alive(_hp), AMovable(_dir, 0) {
	Entity(_pos.x, _pos.y);
	std::cout << "Player just created at x = " << _pos.x << " and y = " << _pos.y << " with " << _hp << " life with direction x = " << _dir.x << " and y = " << _dir.y << std::endl;
}

void Player::TakeDamage(float _dmg) {
	Alive::TakeDamage(_dmg);
	std::cout << "Player just die" << std::endl;
}

void Player::Move() {
	Position += Direction * Speed;
	std::cout << "Player move to x = " << Position.x << " and y = " << Position.y << std::endl;
}

void Player::Attack(Alive& _target) {
	std::cout << "Player just attacked" << std::endl;
	_target.TakeDamage(10);
}