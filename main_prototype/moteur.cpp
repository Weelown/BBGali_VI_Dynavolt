/*
* @Author: Romain_Gérardin
* @Date:   2016-10-29 01:45:48
* @Last Modified by:   Romain_Gérardin
* @Last Modified time: 2016-10-29 11:15:07
*/


#include "moteur.h"
#include "Arduino.h"

	
	Moteur::Moteur()
	:m_nom("Default"), m_valeur(0), m_etat("Initialisation")
	{}

	Moteur::Moteur(Moteur const& cop)
	:m_nom(cop.m_nom), m_valeur(cop.m_valeur), m_etat(cop.m_etat)
	{}

	Moteur::Moteur(String _nom, int _valeur, String _etat)
	:m_nom(_nom), m_valeur(_valeur), m_etat(_etat)
	{}

	String Moteur::get_nom(){return m_nom;}
	int Moteur::get_valeur(){return m_valeur;}
	String Moteur::get_etat(){return m_etat;}

	void Moteur::set_valeur(int _valeur){m_valeur = _valeur;}
	void Moteur::set_etat(String _etat){m_etat = _etat;}


void Moteur::affichage_moteur()  //Fonction d'affichage des différentes informations du robot
{	
	Serial.println(get_nom());
	Serial.print("Valeur moteur : ");
	Serial.println(get_valeur());  //Affichage de la valeur de son état
	Serial.print("Etat moteur");
	Serial.println(get_etat());  //ffichage de son état
}