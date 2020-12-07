#include "Detecteurdepoussiere.h"

Detecteurdepoussiere::Detecteurdepoussiere() {
    niveau = 0;
    gainArgent = 100;
    tempsDeProduction = 30;
    nom = "Detecteur de Poussiere";
    coutAmelioration = 1000;
    acheter = false;
    prerequis = "Balayage rapide NIV 15";
    numUsine = 2;
}