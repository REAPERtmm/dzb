#include "AbstractEntity.h"

AMovable::AMovable(Vector2& _dir, float _speed) : Direction(_dir), Speed(_speed) {}

Vector2* AMovable::GetDirection() {
	return &Direction;
}

float AMovable::GetSpeed() {
	return Speed;
}

void AMovable::SetDirection(Vector2& _dir) {
	Direction.x = _dir.x;
	Direction.y = _dir.y;
}

void AMovable::SetSpeed(float _speed) {
	Speed = _speed;
}
