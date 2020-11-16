using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestArgent
{
    class Balayagerapide : Usine
    {
        public Balayagerapide( ) 
        {
            niveau = 1;
            coutAmelioration = 200;
            gainArgent = (coutAmelioration * (2 * 2) / 100);
            tempsDeProduction = 10;
            nom = "Stand Menager Balayage Rapide";
            numUsine = 1;
            acheter = true;
            
        }

       
    }
}
