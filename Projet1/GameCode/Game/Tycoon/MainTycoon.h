#pragma once
#include "Banque.h"
#include "Usine.h"
#include <SFML\System\Time.hpp>



class MainTycoon
{
private:
    
  
  
public:
    MainTycoon();
    ~MainTycoon();
    void init();
    static void ameliorer(int valeur);
    void ajouter();
   static std::string AfficherUsine(int value);
   static std::string AfficherBanque();

};


