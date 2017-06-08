#include "stdafx.h"
#include "Triangle.h"
#include "math.h"
#include <iostream>

float Triangle::AngleToRad(float angle)
{
	return angle*3.14/180;
}
int Triangle::CountAngles(float angle)
{
	int count=0;
	if (angle == _angleA) ++count;
	if (angle == _angleB) ++count;
	if (angle == GetAngleC()) ++count;
	return count;
}
Triangle::Triangle(float angleA, float angleB, float base)
{
	SetAngleA(angleA);
	SetAngleB(angleB);
	SetBase(base);
}

void Triangle::initVector(vector<Triangle> &v, const int n, vector<float> &s, int&ind)
{
	for (int i = 0; i < n; ++i) {
		float angleA = s[ind++];
		float angleB = s[ind++];
		float base = s[ind++];	
		Triangle temp(angleA, angleB, base);
		v.insert(v.end(), temp);
	}
	ind--;
}
Triangle::Triangle(Triangle const & other)
{
	this->_angleA = other._angleA;
	this->_angleB = other._angleB;
	this->_base = other._base;
}

float Triangle::GetAngleC()
{
	return 180 - _angleA - _angleB;
}

float Triangle::GetSideB()
{
	float angB = AngleToRad(_angleB);
	float angC = AngleToRad(GetAngleC());
	return sin(angB) / sin(angC)*_base;
}

float Triangle::GetSideA()
{
	float angA = AngleToRad(GetAngleA());
	float angC = AngleToRad(GetAngleC());
	return sin(angA)/sin(angC)*_base;
}

float Triangle::GetBase()
{
	return _base;
}

float Triangle::GetAngleA()
{
	return _angleA;
}

float Triangle::GetAngleB()
{
	return _angleB;
}

void Triangle::SetBase(float base)
{
	if(base>0)
		_base = base;
	else
		throw invalid_argument("Invalid size!");
}

void Triangle::SetAngleA(float angleA)
{
	if (angleA <=0|| angleA + _angleB >= 180)
		throw invalid_argument("Invalid angles!");
	_angleA = angleA;
}

void Triangle::SetAngleB(float angleB)
{
	if (angleB <= 0 || angleB + _angleA >= 180)
		throw invalid_argument("Invalid angles!");
	_angleB = angleB;
}

bool Triangle::IsSimilarTo(Triangle  other)
{

	return CountAngles(_angleA)==other.CountAngles(other._angleA)
		&& CountAngles(_angleB) == other.CountAngles(other._angleB)
		&& CountAngles(GetAngleC()) == other.CountAngles(other.GetAngleC());
}

float Triangle::GetMedianBase()
{
	return 0.5*sqrt(2*GetSideA()*GetSideA() + 2* GetSideB()*GetSideB() -_base*_base);
}

float Triangle::GetMedianA()
{
	return 0.5*sqrt(2 * _base*_base + 2 * GetSideB()*GetSideB() - GetSideA()*GetSideA());
}

float Triangle::GetMedianB()
{
	return 0.5*sqrt(2 * _base*_base + 2 * GetSideA()*GetSideA() - GetSideB()*GetSideB());
}
