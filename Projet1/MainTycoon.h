#pragma once
#include "Banque.h"
#include "Usine.h"
#include <SFML\System\Time.hpp>



class MainTycoon
{
private:
    Banque* porteFeuille;
    Usine* standMenager[];
    sf::Time increment;
public:
    void init();
    static void ameliorer(int valeur);
    void ajouter();
};


