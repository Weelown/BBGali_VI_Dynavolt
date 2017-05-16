

																		// Arduino informations
																		// -Tension de sortie : 5V continu (cc)
																		// -Fréquence de 16 MHz



//#define TestLed 13  //Définition des pins
#include "moteur.h"
#include "Dynamixel_Serial.h"

Moteur moteur_1("Moteur_1", 3, 0, "Arret"), moteur_2("Moteur_2", 4, 0, "Arret");  //Déclaration nouveau moteur

void setup() {
	pinMode(3, OUTPUT);  //Choix des pins d'entrée et de sortie
	pinMode(4, OUTPUT);  //Choix des pins d'entrée et de sortie
	Serial.begin(9600);  //Initialisation du moniteur
}


void loop()
{

	Dynamixel.begin(200,3);
	Dynamixel.begin(200,4);
	Dynamixel.endlessEnable(3,1);
	Dynamixel.endlessEnable(4,1);
	Dynamixel.turn(3,1,200);
	Dynamixel.turn(4,0,200);
	Serial.println(Dynamixel.readPosition(3));
	Serial.println(Dynamixel.readPosition(4));
	// analogWrite(3, 200);
	// analogWrite(4, 200);

	// moteur_1.acceleration_moteur(255);
	// moteur_2.acceleration_moteur(255);

	// analogWrite(moteur_1.get_id(), 255);						Tests
	// analogWrite(moteur_2.get_id(), 255);

	//moteur_1.affichage_moteur();

	// moteur_1.deceleration_moteur(100);
	// moteur_1.affichage_moteur();

	// moteur_1.acceleration_moteur(200);
	// moteur_1.affichage_moteur();

	//moteur_1.deceleration_moteur(0);

}
