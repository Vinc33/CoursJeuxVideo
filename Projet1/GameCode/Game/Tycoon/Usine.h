#pragma once
#include <string>

class Usine
{
protected :
	int niveau;
	int tempsDeProduction;
	std::string nom;
	int coutAmelioration;
	bool acheter;
	
	std::string prerequis;
	int valeurRevente;
	int numUsine;
	int gainArgent;
private:
	double tempsEstime;
	
public :
	Usine();
	Usine(std::string nom, int coutAmelioration, std::string prerequis, int numUsine, int gainArgent);
	void amelioration();
	std::string to_string();
	int getNumUsine();
	int getCoutAmelioration();
	int getNiveau();
	int getTempdeProduction();
	int getGainArgent();
	bool getAcheter();
};

