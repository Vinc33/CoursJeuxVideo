#pragma once
#include "Banque.h"
#include "Usine.h"
class MainTycoon
{
private:
    Banque* portefeuille;
    Usine* StandMenager[];

public:
    MainTycoon();
    void ameliorer();
};

