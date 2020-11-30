using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestArgent
{
    class AspirateurQuantique : Usine
    {
        public AspirateurQuantique()
        {
            niveau = 0;
            this.gainArgent =100;
            this.tempsDeProduction = 30;
            this.nom = "Aspirateur Quantique(";
            this.coutAmelioration = 1000;
            acheter = false;
            prerequis = "CPU Ameliorer NIV 15";
            numUsine = 5;
        }
    }
}
