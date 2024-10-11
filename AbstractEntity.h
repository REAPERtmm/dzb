#pragma once

#include "Vector2.h"

#ifndef __ABSTRACT_ENTITY__
#define __ABSTRACT_ENTITY__

class AMovable {
protected:
	Vector2 Direction;
	float Speed;
public:
	AMovable(Vector2&, float);
	virtual Vector2* GetDirection();
	virtual float GetSpeed();
	virtual void SetDirection(Vector2&);
	virtual void SetSpeed(float);
	virtual void Move() = 0;
};

#endif // !__ABSTRACT_ENTITY__

