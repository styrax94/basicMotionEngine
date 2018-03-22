#pragma once
#include "Vector3D.h"
#include <math.h>
class Vector3DMaths
{
public:
	static Vector3D addVector(Vector3D vecA, Vector3D vecB);
	static Vector3D subtractVector(Vector3D vecA, Vector3D vecB);
	static float dotProduct(Vector3D vecA, Vector3D vecB);
	static Vector3D normalize(Vector3D vecA);
	static float getMagnitude(Vector3D vec);
	static Vector3D scalarMultiply(Vector3D vec, float x);
private:
	Vector3DMaths() {};
};

