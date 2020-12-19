#pragma once
#include "FactoryUsine.h"

class MainTycoon
{
private:

	Banque* porteFeuille;

public:

	MainTycoon();
	~MainTycoon();
	Usine* standMenager[30];

	void ameliorer(int valeur);
	void ajouter();
	std::string AfficherUsine(int value);
	std::string AfficherBanque();

};


