using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestArgent
{
    class FactoryUsine
    {
        public FactoryUsine()
        {

        }
        public Usine creation(int numUsine)
        {
            Usine usine = new Usine();
            switch (numUsine)
            {
                case 1: usine = new Detecteurdepoussiere(); break;
                case 2: usine = new BalaiVibranium(); break;
                case 3: usine = new CPUAmeliorer(); break;
                case 4: usine = new AspirateurQuantique(); break;

            }
            return usine;
            
        }
        public Usine creation()
        {
            Usine usine = new Balayagerapide();
            
            return usine;

        }
    }
}
