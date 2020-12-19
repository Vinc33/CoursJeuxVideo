#include "MainTycoon.h"


 MainTycoon::MainTycoon()
{
     porteFeuille = new Banque();
     
     for (int i = 0; i < 30; i++) {
         standMenager[i] = FactoryUsine::CreerUsine(i);
    }
}

 MainTycoon::~MainTycoon() {
     delete porteFeuille;
     delete standMenager;
     
 }


void MainTycoon::ameliorer(int valeur) {
    if (standMenager[valeur]->getCoutAmelioration() <= porteFeuille->getSomme() && standMenager[valeur]->getAcheter() == true) // améliore
    {
    porteFeuille->enleverArgent(standMenager[valeur]->getCoutAmelioration());
    standMenager[valeur]->amelioration();
    }
    else if (standMenager[valeur]->getAcheter() == false && standMenager[valeur-1]->getNiveau() >= 15 && standMenager[valeur]->getCoutAmelioration() <= porteFeuille->getSomme()) { // Achat de l'husine
        
        porteFeuille->enleverArgent(standMenager[valeur]->getCoutAmelioration());
        standMenager[valeur]->amelioration();
        
    }
    
}

void MainTycoon::ajouter()
{
    int i = 0;
    while (standMenager[i]->getAcheter() == true) {

        porteFeuille->ajouterArgent(standMenager[i]->getGainArgent());
        i++;
    }
  }


std::string MainTycoon::AfficherUsine(int value) {
    return standMenager[value]->to_string();
}

std::string MainTycoon::AfficherBanque() {
    std::string message = porteFeuille->AfficherPortefeuille();
    return  message;
}
