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
	Position = Vector2(_x, _y);
	std::cout << "Static Object just created at x = " << _x << " and y = " << _y << std::endl;
}

// BREAKABLEOBJECT =================================

BreakableObject::BreakableObject(float _x, float _y, float _hp) : Alive(_hp){
	Position = Vector2(_x, _y);
	std::cout << "Breakable Object just created at x = " << _x << " and y = " << _y << " with " << _hp << " hp" << std::endl;
}

void BreakableObject::TakeDamage(float _dmg) {
	Alive::TakeDamage(_dmg);
	if (GetHP() <= 0) {
		std::cout << "Breakable Object just broke" << std::endl;
	}
}

// MOB =================================

Mob::Mob(Vector2& _pos, Vector2& _dir, float _hp) : Alive(_hp), AMovable(_dir, 0) {
	Position = Vector2(_pos.x, _pos.y);
	std::cout << "Mob just created at x = " << _pos.x << " and y = " << _pos.y << " with " << _hp << " life with direction x = " << _dir.x << " and y = " << _dir.y << std::endl;
}

void Mob::TakeDamage(float _dmg) {
	Alive::TakeDamage(_dmg);
	std::cout << "Mob Just Take " << _dmg << " dmg" << std::endl;
	if(HP <= 0) std::cout << "Mob just die" << std::endl;
}

void Mob::Move() {
	Position = Position + Direction * Speed;
	std::cout << "Mob move to x = " << Position.x << " and y = " << Position.y << " | " << Direction.toString() << " | " << Speed << std::endl;
}

// PLAYER =================================

Player::Player(Vector2& _pos, Vector2& _dir, float _hp) : Alive(_hp), AMovable(_dir, 0) {
	Position = Vector2(_pos.x, _pos.y);
	std::cout << "Player just created at x = " << _pos.x << " and y = " << _pos.y << " with " << _hp << " life with direction x = " << _dir.x << " and y = " << _dir.y << std::endl;
}

void Player::TakeDamage(float _dmg) {
	Alive::TakeDamage(_dmg);
	std::cout << "Player just die" << std::endl;
}

void Player::Move() {
	Position = Position + Direction * Speed;
	std::cout << "Player move to x = " << Position.x << " and y = " << Position.y << " | " << Direction.toString() << " | " << Speed << std::endl;
}

void Player::Attack(Alive& _target) {
	std::cout << "Player just attacked" << std::endl;
	_target.TakeDamage(10);
}