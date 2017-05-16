/*
* @Author: Romain_G�rardin
* @Date:   2016-11-15 15:38:19
* @Last Modified by:   Weelown
* @Last Modified time: 2016-11-16 11:45:55
*/


#define pi 3.1415926536
#define ABSCISSE_DEPART 0
#define ORDONNE_DEPART 0
#define RAYON_DEPART sqrt((ABSCISSE_DEPART^2)+(ORDONNE_DEPART^2))

#if defined ABSCISSE_DEPART == 0
#define ANGLE_DEPART = pi / 2
#else
#define ANGLE_DEPART atan(ORDONNE_DEPART / ABSCISSE_DEPART)
#endif

// #include <iostream>
#include <math.h>
#include "robot.h"

using namespace std;


	Robot::Robot()
	:m_x(ABSCISSE_DEPART),m_y(ORDONNE_DEPART),m_r(RAYON_DEPART),m_angle(ANGLE_DEPART),m_moteur_droit(Moteur("Moteur_droit", 0, "Arret")),m_moteur_gauche(Moteur("Moteur_gauche", 0, "Arret"))
	{}

	void Robot::set_x(float _x) {m_x = _x;}
	void Robot::set_y(float _y) {m_y = _y;}
	void Robot::set_r(float _r) {m_r = _r;}
	void Robot::set_angle(float _angle) {m_angle = _angle;}

	float Robot::get_x() {return m_x;}
	float Robot::get_y() {return m_y;}
	float Robot::get_r() {return m_r;}
	float Robot::get_angle() {return m_angle;}
	
	Moteur Robot::get_moteur_droit() {return m_moteur_droit;}
	Moteur Robot::get_moteur_gauche() {return m_moteur_gauche;}
