#pragma once
#include "FactoryUsine.h"

class MainTycoon
{
private:

	Banque* porteFeuille;

public:

	MainTycoon();
	~MainTycoon();
	void init();
	Usine* standMenager[15];

	void ameliorer(int valeur);
	void ajouter();
	std::string AfficherUsine(int value);
	std::string AfficherBanque();

};


