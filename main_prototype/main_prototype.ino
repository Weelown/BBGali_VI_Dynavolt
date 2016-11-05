

																		// Arduino informations
																		// -Tension de sortie : 5V continu (cc)
																		// -Fréquence de 16 MHz



#define TestLed 10  //Définition des pins
#include "moteur.h"


void setup() {
	pinMode(TestLed, OUTPUT);  //Choix des pins d'entrée et de sortie
	Serial.begin(9600);  //Initialisation du moniteur
}



int main()
{
	Moteur moteur_1("Moteur_1", 0, "Arret"), moteur_2("Moteur_2", 0, "Arret");  //Déclaration nouveau moteur

	moteur_1.set_valeur(255); //Mise à 1 logic du moteur
	moteur_1.set_etat("Marche avant");

	moteur_1.affichage_moteur();  //Affichage de toutes les informations relative au moteur
	analogWrite(TestLed, moteur_1.get_valeur());  //On effectue les changements (ici faire avancer le moteur)

	return 0;
}
