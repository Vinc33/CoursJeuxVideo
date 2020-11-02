#pragma once
class Vector2f
{
	//Attributs
public:
	float x;
	float y;

	//Methods
public:
	Vector2f(float x, float y);
	~Vector2f();
	void Add(Vector2f Vector2f);
	void Substract(Vector2f Vector2f);
	void Multiply(float scalair);
	void Divide(float scalaire);
};

