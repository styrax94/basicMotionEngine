#include "Vector2DMaths.h"



Vector2D Vector2DMaths::addVector(Vector2D vectorA, Vector2D vectorB)
{
	Vector2D result = Vector2D(vectorA.X + vectorB.X, vectorA.Y + vectorB.Y);
	return result;
}

Vector2D Vector2DMaths::subtractVector(Vector2D vectorA, Vector2D vectorB)
{
	Vector2D result = Vector2D(vectorA.X - vectorB.X, vectorA.Y - vectorB.Y);
	return result;
}

float Vector2DMaths::dotProduct(Vector2D vectorA, Vector2D vectorB)
{
	float a = vectorA.X * vectorB.X;
	float b = vectorA.Y * vectorB.Y;
	
	return a+b;

}
float Vector2DMaths::getMagnitude(Vector2D vec)
{
   return sqrtf((vec.X*vec.X) + (vec.Y*vec.Y));
}
Vector2D Vector2DMaths::normalize(Vector2D vec)
{
	float magn = getMagnitude(vec);
	Vector2D result = Vector2D(vec.X / magn, vec.Y / magn);
	return result;
}

Vector2D Vector2DMaths::scalarMultiply(Vector2D vec, float x)
{
	Vector2D result = Vector2D(vec.X * x, vec.Y * x);
	return result; 
}

Vector2D Vector2DMaths::getVelocityVector(float speed, float angle)
{
	Vector2D vec = Vector2D(speed*cos(angle*(3.14159265f / 180)),speed*sin(angle*(3.14159265f / 180)));
	
	return vec;
}
Vector2D Vector2DMaths::rotateVector(Vector2D vector, float angle)
{
	 
	float x = (vector.X * cos(angle*(3.14159265f / 180)) - (vector.Y * sin(angle*(3.14159265f / 180))));
	float y = (vector.X * sin(angle*(3.14159265f / 180))) + (vector.Y * cos(angle*(3.14159265f / 180)));
	
	Vector2D vec = Vector2D(x, y);

	
	return vec;
}

