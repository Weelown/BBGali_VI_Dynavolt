/*
* @Author: Romain_Gérardin
* @Date:   2016-10-29 01:45:48
* @Last Modified by:   Weelown
* @Last Modified time: 2016-11-15 14:11:11
*/


#include "moteur.h"
#include "Arduino.h"
#define TestLed 11

	
	Moteur::Moteur()
	:m_nom("Default"), m_valeur(0), m_etat("Initialisation")
	{}

	Moteur::Moteur(Moteur const& cop)
	:m_nom(cop.m_nom), m_id(cop.m_id), m_valeur(cop.m_valeur), m_etat(cop.m_etat)
	{}

	Moteur::Moteur(String _nom, unsigned char _id, int _valeur, String _etat)
	:m_nom(_nom), m_id(_id), m_valeur(_valeur), m_etat(_etat)
	{}

	String Moteur::get_nom(){return m_nom;}
	int Moteur::get_valeur(){return m_valeur;}
	String Moteur::get_etat(){return m_etat;}
	unsigned char Moteur::get_id() {return m_id;}

	void Moteur::set_valeur(int _valeur){m_valeur = _valeur;}
	void Moteur::set_etat(String _etat){m_etat = _etat;}

	void Moteur::acceleration_moteur(int i)
	{
		for(int j = m_valeur; j < i + 1; j++)
		{
			set_valeur(j);
			analogWrite(get_id(), get_valeur());
			delay(20);
		}
		set_etat("En marche avant");
	}

	void Moteur::deceleration_moteur(int i)
	{
		for(int j = m_valeur; j > i - 1; j--)
		{
			set_valeur(j);
			analogWrite(get_id(),get_valeur());
			delay(20);
		}
		set_etat("Arret");
	}


void Moteur::affichage_moteur()  //Fonction d'affichage des différentes informations du robot
{	
	Serial.println(get_nom());
	Serial.print("Valeur moteur : ");
	Serial.println(get_valeur());  //Affichage de la valeur de son état
	Serial.print("Etat moteur : ");
	Serial.println(get_etat());  //ffichage de son état
	Serial.println(" ");
}

