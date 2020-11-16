using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestArgent
{
    class menu
    {
        public void AchatAmélioration(ref Usine Stand, Banque portefeuille)
        {
            if (Stand.coutAmelio <= portefeuille.Argent)
            {
                portefeuille.EnleverArgent(Stand.coutAmelio);
                Stand.Amélioration();
            }
        }
       
    }
}
