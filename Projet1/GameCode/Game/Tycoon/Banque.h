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
    std::string to_String();
    int getSomme();
};

