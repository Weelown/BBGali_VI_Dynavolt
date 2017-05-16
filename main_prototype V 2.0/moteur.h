#ifndef moteur_h
#define moteur_h
#include "Arduino.h"


class Moteur  //Initialisation de la structure moteur
{	
private:
	String m_nom;
	int m_valeur;
	String m_etat;
	unsigned char m_id;

public: 
	Moteur();
	Moteur(Moteur const& cop);
	Moteur(String _nom, unsigned char _id, int _valeur, String _etat);

	void affichage_moteur();
	void acceleration_moteur(int i);
	void deceleration_moteur(int i);

	String get_nom();
	int get_valeur();
	String get_etat();
	unsigned char get_id();

	void set_valeur(int _valeur);
	void set_etat(String _etat);
};


#endif