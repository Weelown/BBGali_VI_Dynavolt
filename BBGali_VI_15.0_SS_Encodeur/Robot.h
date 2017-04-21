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
  unsigned int m_x;
  unsigned int m_y;

  unsigned int m_x_arrive;
  unsigned int m_y_arrive;
  
  float m_r;
  float m_angle;
  float m_dangle;

  Moteur m_moteur_droit;
  Moteur m_moteur_gauche;

}Robot;

#endif
