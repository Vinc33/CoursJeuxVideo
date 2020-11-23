#include "Usine.h"

Usine::Usine() {
	debloquer = false;
	valeurRevente = 0;
}

void Usine::amelioration() {
    if (niveau == 0) // Achat Stand
    {
        acheter = true;
        niveau += 1;
        coutAmelioration += (coutAmelioration * 2);
        gainArgent += coutAmelioration * (2 * 2 / 100);

    }
    else // Amelioration stat stand
    {
        niveau += 1;
        coutAmelioration += (coutAmelioration * 2);
        gainArgent += coutAmelioration * (4 * 2) / 100;
        tempsDeProduction -= 0.2;
        tempsEstime = coutAmelioration / gainArgent * tempsDeProduction / 60;
        valeurRevente += (coutAmelioration * 4 / 100);
    }
}
std::string Usine::to_string() {
    if (acheter == false)
    {
        return nom + "\n Prix :" + std::to_string(coutAmelioration) + "\nPrerequis : " + prerequis;
    }
    else
    {
        return nom + "\n Prix :" + std::to_string(coutAmelioration) + "\n Niveau " + std::to_string(niveau) + "\n Gain dargent : " + std::to_string(gainArgent) + "\nValeur de revente : " + std::to_string(valeurRevente) + "\n";
    }
}
    int Usine::getNumUsine() {
        return numUsine;
    }

