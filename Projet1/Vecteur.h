#pragma once
class Vecteur
{
	//Attributs
public:
	float x;
	float y;

	//Methods
public:
	Vecteur(float x, float y);
	~Vecteur();
	void Add(Vecteur vecteur);
	void Substract(Vecteur vecteur);
	void Multiply(float scalair);
	void Divide(float scalaire);
};

