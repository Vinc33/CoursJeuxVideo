#include "Balayagerapide.h"

Balayagerapide::Balayagerapide() {
    niveau = 1;
    coutAmelioration = 200;
    gainArgent = (coutAmelioration * (2 * 2) / 100);
    tempsDeProduction = 10;
    nom = "Balayage Rapide";
    numUsine = 1;
    acheter = true;
}