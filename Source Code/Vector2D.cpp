 #include "Vector2D.h"
#include <iostream>
using namespace std;


Vector2D::Vector2D(float x, float y)
{
	X = x;
	Y = y;
}

Vector2D::Vector2D()
{
}

void Vector2D::printVector()
{
	cout << "( " << X << ", " << Y << " )"; 
}

//addition, subtractions, dot product, normalize