#pragma once
#include <iostream>
using namespace std;
class Vector3D
{
public:
	Vector3D(float x, float y, float z);
	Vector3D();
	float X, Y, Z;
	void printVector();
};

