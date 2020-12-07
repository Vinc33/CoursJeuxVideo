#include "AspirateurQuantique.h"

AspirateurQuantique::AspirateurQuantique() {
    niveau = 0;
    gainArgent = 100;
    tempsDeProduction = 30;
    nom = "Aspirateur Quantique(";
    coutAmelioration = 1000;
    acheter = false;
    prerequis = "CPU Ameliorer NIV 15";
    numUsine = 5;
}