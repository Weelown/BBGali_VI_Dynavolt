#ifndef robot_h
#define robot_h

#include "moteur.h"

class Robot
{
private:
	float m_x;
	float m_y;
	float m_r;
	float m_angle;
	Moteur m_moteur_droit;
	Moteur m_moteur_gauche;

public:
	Robot();

	void set_x(float _x);
	void set_y(float _y);
	void set_r(float _r);
	void set_angle(float _angle);

	float get_x();
	float get_y();
	float get_r();
	float get_angle();
	Moteur get_moteur_droit();
	Moteur get_moteur_gauche();
};

#endif
