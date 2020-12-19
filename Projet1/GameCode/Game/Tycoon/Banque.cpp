#include "Banque.h"
Banque::Banque()
{
    argent = 1000; //somme d'argent au debut
}

 void Banque::ajouterArgent(int ajout)
{
    argent += ajout;
}
 void Banque::enleverArgent(int retrait)
{
    argent -= retrait;
}
std::string Banque::AfficherPortefeuille()
{
    std::string message = "Somme : " + std::to_string(argent);
    return message; 
}

int Banque::getSomme() {
    return argent;
}

 
