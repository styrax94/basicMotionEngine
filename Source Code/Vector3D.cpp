#include "Vector3D.h"



Vector3D::Vector3D(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}
Vector3D::Vector3D()
{

}
void Vector3D:: printVector()
{
	cout << "( " << X << ", " << Y << ", " << Z << " )";
}


