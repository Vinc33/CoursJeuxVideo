#pragma once
#include <string>

class Usine
{
protected :
	int niveau;
	double tempsDeProduction;
	std::string nom;
	int coutAmelioration;
	bool acheter;
	bool debloquer;
	std::string prerequis;
	int valeurRevente;
	int numUsine;
	int gainArgent;
private:
	double tempsEstime;
	
public :
	Usine();
	void amelioration();
	std::string to_string();
	int getNumUsine();
};

