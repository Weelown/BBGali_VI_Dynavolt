#include "Robot.h"


void init_robot(Robot& monRobot)
{
  monRobot.m_x = ABSCISSE_DEPART;
  monRobot.m_y = ORDONNE_DEPART;

  monRobot.m_r = RAYON_DEPART;
  monRobot.m_angle = ANGLE_DEPART;
  monRobot.m_dangle = ANGLE_DEPART;

  monRobot.m_x_arrive = ABSCISSE_DEPART;
  monRobot.m_y_arrive = ORDONNE_DEPART;

  monRobot.m_moteur_gauche.m_id = MOTEUR_GAUCHE_ID; 
  monRobot.m_moteur_droit.m_id = MOTEUR_DROIT_ID; 
}