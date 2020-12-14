#pragma once
#include "Usine.h"
#include "Banque.h"

class FactoryUsine
{
public:
	static Usine* CreerUsine();
	static Usine* CreerUsine(int numUsine);
	static Banque* creerBanque();
};

