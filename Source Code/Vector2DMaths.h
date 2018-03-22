#pragma once
#include "Vector2D.h"
#include <math.h>

class Vector2DMaths
{
public:
	
	static Vector2D addVector(Vector2D vecA, Vector2D vecB);
	static Vector2D subtractVector(Vector2D vecA, Vector2D vecB);
	static float dotProduct(Vector2D vecA, Vector2D vecB);
	static Vector2D normalize(Vector2D vecA);
	static float getMagnitude(Vector2D vec);
	static Vector2D scalarMultiply(Vector2D vec, float x);
	static Vector2D rotateVector(Vector2D vec, float angle);
	static Vector2D getVelocityVector(float speed, float angle);
private:
	Vector2DMaths() {};
};

