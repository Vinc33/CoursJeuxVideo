using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace TestArgent
{
    /// <summary>
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private Banque portefeuille = new Banque();
        private Usine[] StandMenager = new Usine[4];
        private double [] increment = new double[5];
        private menu menu = new menu();
        private FactoryUsine Factory = new FactoryUsine();
        public MainWindow()
        {
            StandMenager[0] = Factory.creation();
            StandMenager[1] =Factory.creation(StandMenager[0].NumUsine);
            
            increment[0] = StandMenager[0].tempsDeProd;
            increment[1] = StandMenager[1].tempsDeProd; ;
            InitializeComponent();
            portefeuilles.Text = portefeuille.ToString();
            Usine1.Text = StandMenager[0].ToString();
            Usine2.Text = StandMenager[1].ToString();
            DispatcherTimer timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromSeconds(1);
            timer.Tick += timer_Tick;
            timer.Start();
        }
        public void Usine1Click(object sender, RoutedEventArgs e) // Bouton Usine 1
        {
            if (StandMenager[0].coutAmelio <= portefeuille.Argent)
            {
                menu.AchatAmélioration(ref StandMenager[0], portefeuille);
                portefeuilles.Text = portefeuille.ToString();
                increment[0]--;
                Usine1.Text = StandMenager[0].ToString();
            }
        }
        public void Usine2CLick(object sender, RoutedEventArgs e) // Bouton Usine 2
        {
            améliorer(1);
            Usine2.Text = StandMenager[1].ToString();
            lblTime2.Content = increment[1].ToString();
        }
        public void améliorer(int valeur)
        {
            if (StandMenager[valeur].coutAmelio <= portefeuille.Argent && StandMenager[valeur - 1].Niveau >= 15)
            {
                menu.AchatAmélioration(ref StandMenager[valeur], portefeuille);
                portefeuilles.Text = portefeuille.ToString();
                increment[valeur]--;
                StandMenager[valeur + 1] = Factory.creation(StandMenager[valeur].NumUsine);
            }
        }
        
        void timer_Tick(object sender, EventArgs e)
        {
            increment[0]--;
            
            lblTime.Content = increment[0].ToString();
            if(StandMenager[1].Acheter == true)
            {
                increment[1]--;
                lblTime2.Content = increment[1].ToString();
            }
            
            Ajouter();
        }
        public void Ajouter()
        {
                if(increment[0] <= 0)
                {
                    increment[0] = StandMenager[0].tempsDeProd;
                    portefeuille.AjouterArgent(StandMenager[0].GainArgent);
                    portefeuilles.Text = portefeuille.ToString();
                } 
                 if (StandMenager[1].Acheter == true)
                 {
                    if (increment[1] <= 0)
                     {
                    increment[1] = StandMenager[1].tempsDeProd;
                    portefeuille.AjouterArgent(StandMenager[1].GainArgent);
                    portefeuilles.Text = portefeuille.ToString();
                     }
                 }
               

        }

    }
}
