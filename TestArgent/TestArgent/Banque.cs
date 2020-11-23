using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestArgent
{
    class Banque
    {
        private int argent;
      
        public Banque()
        {
            argent = 1000; //somme d'argent au debut
        }
        
        public void AjouterArgent(int ajout)
        {
            argent += ajout;
        }
        public void EnleverArgent(int retrait)
        {
            argent -= retrait;
        }
        public override string ToString()
        {
            return "Somme : "+ argent;
        }
        public int Argent { get { return argent; } }
    }
}
