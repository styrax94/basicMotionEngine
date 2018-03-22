#include "Vector3DMaths.h"


Vector3D Vector3DMaths::addVector(Vector3D vectorA, Vector3D vectorB)
{
	Vector3D result = Vector3D(vectorA.X + vectorB.X, vectorA.Y + vectorB.Y, vectorA.Z + vectorB.Z);
	return result;
}

Vector3D Vector3DMaths::subtractVector(Vector3D vectorA, Vector3D vectorB)
{
	Vector3D result = Vector3D(vectorA.X - vectorB.X, vectorA.Y - vectorB.Y, vectorA.Z - vectorB.Z);
	return result;
}

float Vector3DMaths::dotProduct(Vector3D vectorA, Vector3D vectorB)
{
	float a = vectorA.X * vectorB.X;
	float b = vectorA.Y * vectorB.Y;
	float c = vectorA.Z * vectorB.Z;

	return a + b + c;

}
float Vector3DMaths::getMagnitude(Vector3D vec)
{
	return sqrtf((vec.X*vec.X) + (vec.Y*vec.Y) + (vec.Z* vec.Z));
}
Vector3D Vector3DMaths::normalize(Vector3D vec)
{
	float magn = getMagnitude(vec);
	Vector3D result = Vector3D(vec.X / magn, vec.Y / magn, vec.Z/magn);
	return result;
}

Vector3D Vector3DMaths::scalarMultiply(Vector3D vec, float x)
{
	Vector3D result = Vector3D(vec.X * x, vec.Y * x, vec.Z* x);
	return result; 
}


