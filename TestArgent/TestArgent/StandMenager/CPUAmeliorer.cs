using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestArgent
{
    class CPUAmeliorer : Usine
    {
        public CPUAmeliorer()
        {
            niveau = 0;
            this.gainArgent =100;
            this.tempsDeProduction = 30;
            this.nom = "CPU Ameliorer";
            this.coutAmelioration = 1000;
            acheter = false;
            prerequis = "Balai Vibranium NIV 15";
            numUsine = 3;
        }
    }
}
