using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestArgent
{
    class Usine
    {
        protected int niveau;
        protected int gainArgent;
        protected double tempsDeProduction;
        protected string nom;
        protected int coutAmelioration;
        protected bool acheter;
        protected bool debloquer;
        protected string prerequis;
        protected int valeurRevente;
        private double tempsEstime;
        protected int numUsine;
        public Usine()
        {
            debloquer = false;
            valeurRevente = 0;
        }
        public void Amélioration()
        { if (niveau == 0) // Achat Stand
            {
                acheter = true;
                niveau += 1;
                coutAmelioration += (coutAmelioration * 2);
                gainArgent += coutAmelioration * (2*2 / 100);
                
            }
            else // Amelioration stat stand
            {
                niveau += 1;
                coutAmelioration += (coutAmelioration * 2);
                gainArgent += coutAmelioration*(4*2)/100;
                tempsDeProduction -= 0.2;
                tempsEstime = coutAmelioration / gainArgent * tempsDeProduction / 60;
                valeurRevente += (coutAmelioration * 4 / 100);
            }
       

        }
        public override string ToString()   
        {
            if (acheter == false)
            {
                return noms + "\n Prix :" + coutAmelioration+"\nPrerequis : "+prerequis;
            }
            else
            {
                return noms + "\n Prix :" + coutAmelioration + "\n Niveau " + Niveau + "\n Gain dargent : " + gainArgent + "\ntemps estimer en minute : "+ tempsEstime.ToString("0.00") + "\nValeur de revente : " + valeurRevente+"\n";
            }
               
        }
        
        public int Niveau {  get { return niveau; } }
        public int GainArgent {  get { return gainArgent; } }
        public double tempsDeProd {  get { return tempsDeProduction; } set { tempsDeProduction = value; } }
        public string noms { get { return nom; } }
        public int coutAmelio { get { return coutAmelioration; } }
        public bool Acheter { get { return acheter; } }
        public bool Debloquer { get { return debloquer; } }
        public int NumUsine { get { return numUsine; } }
    }
}
