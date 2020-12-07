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
std::string Banque::ToString()
{
    return "Somme : " + argent;
}

int Banque::getSomme() {
    return argent;
}

 
