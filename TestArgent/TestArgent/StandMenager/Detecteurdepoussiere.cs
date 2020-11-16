using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestArgent
{
    class Detecteurdepoussiere : Usine
    {
        public Detecteurdepoussiere()
        {
            niveau = 0;
            this.gainArgent =100;
            this.tempsDeProduction = 30;
            this.nom = "Detecteur de Poussiere";
            this.coutAmelioration = 1000;
            acheter = false;
            prerequis = "Balayage rapide NIV 15";
            numUsine = 2;
        }
    }
}
