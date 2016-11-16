

																		// Arduino informations
																		// -Tension de sortie : 5V continu (cc)
																		// -Fréquence de 16 MHz



#define TestLed 11  //Définition des pins
#include "moteur.h"
#include "robot.h"


// Moteur moteur_1({"Moteur_1", 0, "Arret"}), moteur_2("Moteur_2", 0, "Arret");  //Déclaration nouveau moteur

void setup() {
	pinMode(TestLed, OUTPUT);  //Choix des pins d'entrée et de sortie
	Serial.begin(9600);  //Initialisation du moniteur
}


void loop()
{	
	Robot BBGali();
	// BBGali.get_moteur_droit().affichage_moteur();

	// moteur_1.acceleration_moteur(100);
	// moteur_1.affichage_moteur();

	// moteur_1.deceleration_moteur(0);

}
