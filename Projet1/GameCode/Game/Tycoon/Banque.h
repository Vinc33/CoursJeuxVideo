#pragma once
#include <string>
class Banque
{ 
private:
    int argent;
public:

    Banque();
    void ajouterArgent(int ajout);
    void enleverArgent(int retrait);
    std::string AfficherPortefeuille();
    int getSomme();
};

