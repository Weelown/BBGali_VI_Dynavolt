#ifndef Deplacement_h
#define Deplacement_h

#include <math.h>
#include <time.h>
#include "DynamixelSerial2.h"
#include "Robot.h"

void arret_moteurs();
void tourner(Robot& monRobot);
void calcul_pol(Robot& monRobot);
void deplacer_robot(Robot& monRobot, float _x, float _y);
bool calculs_sharp(bool avancer);

#endif