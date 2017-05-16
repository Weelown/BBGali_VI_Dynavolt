#ifndef Robot_h
#define Robot_h

#include <math.h>
#include <time.h>
#include "DynamixelSerial2.h"


typedef struct MX_28
{
  unsigned char m_id;
}Moteur;

typedef struct robot
{
  float m_x;
  float m_y;
  
  float m_r;
  float m_angle;
  float m_dangle;

  float m_x_arrive;
  float m_y_arrive;

  Moteur m_moteur_droit;
  Moteur m_moteur_gauche;

}Robot;

void init_robot(Robot& monRobot);

#endif
