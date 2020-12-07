#include "FactoryUsine.h"
#include "BalaiVibranium.h"
#include "AspirateurQuantique.h"
#include "Balayagerapide.h"
#include "CPUAmeliorer.h"
#include "Detecteurdepoussiere.h"

Usine* FactoryUsine::CreerUsine(int numUsine) {
    Usine* usine = new Usine();
    switch (numUsine)
    {
    case 1: usine = new Detecteurdepoussiere(); break;
    case 2: usine = new BalaiVibranium(); break;
    case 3: usine = new CPUAmeliorer(); break;
    case 4: usine = new AspirateurQuantique(); break;

    }
    return usine;
}
Usine* FactoryUsine::CreerUsine() {
    Usine* usine = new Balayagerapide();

    return usine;
}