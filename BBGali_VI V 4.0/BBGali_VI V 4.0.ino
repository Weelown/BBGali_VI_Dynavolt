#include <math.h>
#include "DynamixelSerial2.h"

#define pi 3.1415926536
#define ABSCISSE_DEPART 0
#define ORDONNE_DEPART 0
#define RAYON_DEPART sqrt((ABSCISSE_DEPART^2)+(ORDONNE_DEPART^2))
#define ANGLE_DEPART 90

#define MOTEUR_DROIT_ID 4
#define MOTEUR_GAUCHE_ID 3

#define RxEnable 14 //Avt
#define TxEnable 15 



typedef struct moteur
{
  String m_nom;
  int m_valeur;
  String m_etat;
  unsigned char m_id;
}Moteur;

typedef struct robot
{
  float m_x;
  float m_y;
  float m_r;
  float m_angle;
  Moteur m_moteur_droit;
  Moteur m_moteur_gauche;
}Robot;


void init_robot(Robot& monRobot)
{
  monRobot.m_x = ABSCISSE_DEPART;
  monRobot.m_y = ORDONNE_DEPART;
  monRobot.m_r = RAYON_DEPART;
  monRobot.m_angle = ANGLE_DEPART;

  monRobot.m_moteur_gauche.m_nom = "Moteur gauche"; 
  monRobot.m_moteur_gauche.m_valeur = 0;
  monRobot.m_moteur_gauche.m_etat = "Arret"; 
  monRobot.m_moteur_gauche.m_id = MOTEUR_GAUCHE_ID; 

  monRobot.m_moteur_droit.m_nom = "Moteur droit"; 
  monRobot.m_moteur_droit.m_valeur = 0;
  monRobot.m_moteur_droit.m_etat = "Arret"; 
  monRobot.m_moteur_droit.m_id = MOTEUR_DROIT_ID; 
}


Robot BBGali;
void setup()
{
	Serial.begin(9600);	
  Dynamixel.begin(1000000,TxEnable,RxEnable);
  Dynamixel.setEndless(3,ON);
  Dynamixel.setEndless(4,ON);
  init_robot(BBGali);
}

void loop()
{
  
Dynamixel.turn(BBGali.m_moteur_gauche.m_id,0,200);
Dynamixel.turn(BBGali.m_moteur_droit.m_id,1,200);
delay(2000);

Dynamixel.turn(BBGali.m_moteur_gauche.m_id,1,200);
Dynamixel.turn(BBGali.m_moteur_droit.m_id,0,200);
delay(2000);

Dynamixel.turn(BBGali.m_moteur_gauche.m_id,0,0);
Dynamixel.turn(BBGali.m_moteur_droit.m_id,0,0);
delay(2000);

}
