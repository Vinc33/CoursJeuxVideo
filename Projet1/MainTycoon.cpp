#include "MainTycoon.h"
#include "FactoryUsine.h"
MainTycoon::MainTycoon() {
	portefeuille = new Banque();
	StandMenager[0] = FactoryUsine::CreerUsine();
	StandMenager[1] = FactoryUsine::CreerUsine(StandMenager[0]->getNumUsine());
}
