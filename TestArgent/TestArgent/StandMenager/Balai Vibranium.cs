using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestArgent
{
    class BalaiVibranium : Usine
    {
        public BalaiVibranium()
        {
            niveau = 0;
            this.gainArgent =100;
            this.tempsDeProduction = 30;
            this.nom = "Balai Vibranium";
            this.coutAmelioration = 1000;
            acheter = false;
            numUsine = 4;
            prerequis = "Detecteur de poussiere NIV 15";
        }
    }
}
