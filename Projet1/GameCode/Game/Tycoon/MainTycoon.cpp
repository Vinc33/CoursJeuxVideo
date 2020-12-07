#include "MainTycoon.h"
#include "FactoryUsine.h"
#include <SFML\System\Clock.hpp>

Banque* porteFeuille = new Banque();
Usine* standMenager[15];

 MainTycoon::MainTycoon()
{
   
}
 MainTycoon::~MainTycoon() {
     delete porteFeuille;
     delete standMenager;
     
 }
 void MainTycoon::init() {
     standMenager[0] = FactoryUsine::CreerUsine();
     standMenager[1] = FactoryUsine::CreerUsine(standMenager[0]->getNumUsine());
   
 }
void MainTycoon::ameliorer(int valeur) {
    if (standMenager[valeur]->getAcheter() == false && standMenager[valeur-1]->getNiveau() >= 15 && standMenager[valeur]->getCoutAmelioration() <= porteFeuille->getSomme()) {
        
        porteFeuille->enleverArgent(standMenager[valeur]->getCoutAmelioration());
        standMenager[valeur]->amelioration();
        standMenager[valeur + 1] = FactoryUsine::CreerUsine(standMenager[valeur]->getNumUsine());;
    }
    else if (standMenager[valeur]->getCoutAmelioration() <= porteFeuille->getSomme() && standMenager[valeur]->getAcheter() == true)
    {
        porteFeuille->enleverArgent(standMenager[valeur]->getCoutAmelioration());
        standMenager[valeur]->amelioration();
       
        
       
    }
}

void MainTycoon::ajouter()
{
//    if (increment.asMilliseconds() <= 0)
//    {
///*        increment = standMenager[0]->getTempdeProduction()*/
//        porteFeuille->ajouterArgent(standMenager[0]->getGainArgent());
//       
//    }
//    if (standMenager[1]->getAcheter() == true)
//    {
//        if (increment.asMilliseconds() <= 0)
//        {
//            /*increment = standMenager[1]->getTempdeProduction();*/
//            porteFeuille->ajouterArgent(standMenager[1]->getGainArgent());
//            
//        }
//    }

}
std::string MainTycoon::AfficherUsine(int value) {
    return standMenager[value]->to_string();
}
std::string MainTycoon::AfficherBanque() {
    return porteFeuille->to_String();
}
