#include "FactoryUsine.h"
#include "BalaiVibranium.h"
#include "AspirateurQuantique.h"
#include "Balayagerapide.h"
#include "CPUAmeliorer.h"
#include "Detecteurdepoussiere.h"

Usine* FactoryUsine::CreerUsine(int numUsine) {
    Usine* usine = new Usine();
    switch (numUsine)
    {
    case 0: usine = new Balayagerapide(); break;
    case 1: usine = new Detecteurdepoussiere(); break;
    case 2: usine = new BalaiVibranium(); break;
    case 3: usine = new CPUAmeliorer(); break;
    case 4: usine = new AspirateurQuantique(); break;
    case 5: usine = new Usine("Touillage Plus Rapide",100,"Aspirateur Quantique Niv 15",numUsine+1,100); break;
    case 6: usine = new Usine("Réfrigérateur intégré", 100, "Touillage plus rapide NIV 15", numUsine + 1, 100); break;
    case 7: usine = new Usine("Couteau en Vibranium", 100, "Réfrigérateur intégré NIV 15", numUsine + 1, 100); break;
    case 8: usine = new Usine("CPU Amélioré", 100, "Couteau en Vibranium NIV 15", numUsine + 1, 100); break;
    case 9: usine = new Usine("Gordon Ramsay Mode", 100, "CPU Améliorer NIV 15", numUsine + 1, 100); break;
    case 10: usine = new Usine("NES Classique", 100, "Gordon Ramsay Mode NIV 15", numUsine + 1, 100); break;
    case 11: usine = new Usine("Wii", 100, "NES Classique NIV 15", numUsine + 1, 100); break;
    case 12: usine = new Usine("Mario Kart", 100, "Wii NIV 15", numUsine + 1, 100); break;
    case 13: usine = new Usine("Gaming PC intégré RTX 3090 - Ryzen 9 5000", 100, "MarioKart NIV 15", numUsine + 1, 100); break;
    case 14: usine = new Usine(" VR Headset", 100, "Gaming PC NIV 15", numUsine + 1, 100); break;
    case 15: usine = new Usine("Entrainement de combat basique", 100, "VR Headset NIV 15", numUsine + 1, 100); break;
    case 16: usine = new Usine("Entrainement de combat avancé", 100, " Entraînement de combat basique NIV 15", numUsine + 1, 100); break;
    case 17: usine = new Usine("Armurerie d'armes à feu", 100, "Entraînement de combat avancé NIV 15", numUsine + 1, 100); break;
    case 18: usine = new Usine("Entraînement Seal Team Six", 100, "Armurerie d'armes à feu NIV 15", numUsine + 1, 100); break;
    case 19: usine = new Usine("Terminator", 100, "Entraînement Seal Team Six NIV 15", numUsine + 1, 100); break;
    case 20: usine = new Usine("Entrainement avec le jeu Docteur Maboule - Operation Table", 100, "Terminator NIV 15", numUsine + 1, 100); break;
    case 21: usine = new Usine("Salle d’opération", 100, "Entraînement avec le jeu Docteur Maboule - Operation Table NIV 15", numUsine + 1, 100); break;
    case 22: usine = new Usine("Scalpel et équipements de qualités", 100, " Salle d’opération NIV 15", numUsine + 1, 100); break;
    case 23: usine = new Usine("NUUUUUUUUUUUURSE!!!", 100, "Salle d’opération + Scalpel et équipements de qualités NIV 15", numUsine + 1, 100); break;
    case 24: usine = new Usine("Un robot de Chirurgie Da vinci", 100, "Nurse NIV 15", numUsine + 1, 100); break;
    case 25: usine = new Usine("Vibrateur en Vibranium", 100, "Un robot de Chirurgie Da vinci NIV 15", numUsine + 1, 100); break;
    case 26: usine = new Usine("Electric Nips", 100, "Vibrateur en vibranum NIV 15", numUsine + 1, 100); break;
    case 27: usine = new Usine("Spank-Machine", 100, "Electric Nips NIV 15", numUsine + 1, 100); break;
    case 28: usine = new Usine("Fouet 2.0", 100, "Spank-Machine NIV 15", numUsine + 1, 100); break;
    case 29: usine = new Usine("SupraC0ck", 100, "Fouet 2.0 NIV 15", numUsine + 1, 100); break;
    }
    return usine;
    delete usine;
}
