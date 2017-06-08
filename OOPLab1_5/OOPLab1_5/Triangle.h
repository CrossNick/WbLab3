#pragma once

class Triangle
{
private:
	float _angleA;
	float _angleB;
	float _base;
	float AngleToRad(float angle);
	int CountAngles(float angle);
public:
	Triangle(float angleA, float angleB, float base);
	Triangle(Triangle const& other);
	static void initVector(vector<Triangle> &v, const int n, vector<float> &s, int &i);
	float GetAngleC();
	float GetSideB();
	float GetSideA();
	float GetBase();
	float GetAngleA();
	float GetAngleB();
	void SetBase(float base);
	void SetAngleA(float angleA);
	void SetAngleB(float angleB);
	bool IsSimilarTo(Triangle other);
	float GetMedianBase();
	float GetMedianA();
	float GetMedianB();
};