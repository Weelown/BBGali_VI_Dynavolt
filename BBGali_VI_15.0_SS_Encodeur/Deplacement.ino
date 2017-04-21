#include "Deplacement.h"


void arret_moteurs()
{
	Dynamixel.turn(MOTEUR_GAUCHE_ID,0,VITESSE_MIN);
	Dynamixel.turn(MOTEUR_DROIT_ID,0,VITESSE_MIN);
}

void tourner(Robot& monRobot)
{ 
  int sens;
  float tps;
  int distance;

    if(monRobot.m_dangle > 0)
		{
			sens = 0;
		}
		else
		{
			sens = 1;
		}

		distance = monRobot.m_dangle * RAYON_ENCODEUR;

		tps = distance * TPS_PER_CM;
		
		Dynamixel.turn(MOTEUR_GAUCHE_ID,sens,VITESSE_MAX);
 		Dynamixel.turn(MOTEUR_DROIT_ID,sens,VITESSE_MAX);
 		delay(tps);

		arret_moteurs();
		 			
 		monRobot.m_angle += monRobot.m_dangle;
 		monRobot.m_dangle = 0;
}

void calcul_pol(Robot& monRobot)
{
	float delta_angle, diff, new_angle;

	if(monRobot.m_x != monRobot.m_x_arrive || monRobot.m_y != monRobot.m_y_arrive)
	{
		diff = (monRobot.m_y_arrive - monRobot.m_y) / (monRobot.m_x_arrive - monRobot.m_x);

		monRobot.m_r = sqrt((monRobot.m_x_arrive - monRobot.m_x) * (monRobot.m_x_arrive - monRobot.m_x) + (monRobot.m_y_arrive - monRobot.m_y) * (monRobot.m_y_arrive - monRobot.m_y));				// Calcul de la distance rayon
		
		if(monRobot.m_x_arrive < monRobot.m_x)
		{
			if(monRobot.m_y_arrive >= monRobot.m_y_arrive)
			{
				new_angle = atan(diff);    
			}
			else
			{
				new_angle = atan(diff) + pi;	
			}
		}
		else if(monRobot.m_x_arrive > monRobot.m_x)
		{
			new_angle = atan(diff) - pi;
		}
		else
		{
			if(monRobot.m_y_arrive > monRobot.m_y)
			{
			    new_angle = pi / 2; // (90 deg)
			}
			else
			{
				new_angle =  -1 * pi / 2;  //(-90 deg)
			}
		}

		monRobot.m_dangle = new_angle - monRobot.m_angle;
		
		if (monRobot.m_dangle > pi)
		{
			delta_angle = monRobot.m_dangle - pi;
			monRobot.m_dangle = -1 * pi + delta_angle;
		}
		if (monRobot.m_dangle < -1 * pi)
		{
			delta_angle = monRobot.m_dangle + pi;
			monRobot.m_dangle = pi + delta_angle;
		}
	}
}

void deplacer_robot(Robot& monRobot, float _x, float _y)
{
	monRobot.m_x_arrive = _x;
	monRobot.m_y_arrive = _y;
	float tps,Tps_parcouru;

	calcul_pol(monRobot);

	while((monRobot.m_x_arrive - INCERTITUDE_COORD  >= monRobot.m_x || monRobot.m_x_arrive + INCERTITUDE_COORD <= monRobot.m_x) && (monRobot.m_y_arrive - INCERTITUDE_COORD >= monRobot.m_y || monRobot.m_y_arrive + INCERTITUDE_COORD <= monRobot.m_y))
	{
		if(monRobot.m_dangle != 0)
		{
			tourner(monRobot);
		}
		else
		{
			Tps_parcouru = 0;
			// monRobot.m_r = ((monRobot.m_x_arrive - monRobot.m_x) * (monRobot.m_x_arrive - monRobot.m_x)) + ((monRobot.m_y_arrive - monRobot.m_y) * (monRobot.m_y_arrive - monRobot.m_y));
			// monRobot.m_r  = pow(monRobot.m_r, 0.5);
			tps = monRobot.m_r * TPS_PER_CM;
			do
			{
        // if(calculs_sharp(true) == 1)  // Test sharp
				if(1 == 1)  // Mettre test sharp ici
				{
				  Tps_parcouru += TPS_CHECK_SHARP;
					Dynamixel.turn(monRobot.m_moteur_gauche.m_id,0,VITESSE_MAX);
					Dynamixel.turn(monRobot.m_moteur_droit.m_id,1,VITESSE_MAX);
					delay(TPS_CHECK_SHARP);
					arret_moteurs();
				}
			}while((Tps_parcouru+TPS_CHECK_SHARP) > tps);

      arret_moteurs();

			Dynamixel.turn(monRobot.m_moteur_gauche.m_id,0,VITESSE_MAX);
			Dynamixel.turn(monRobot.m_moteur_droit.m_id,1,VITESSE_MAX);
			delay(tps - Tps_parcouru);

			arret_moteurs();

      monRobot.m_x = monRobot.m_x_arrive;
      monRobot.m_y = monRobot.m_y_arrive;
		}
	}
}

bool calculs_sharp(bool avancer)
{
  int sharp_avant_gauche[5],sharp_avant_droit[5],sharp_diagonale_gauche[5],sharp_diagonale_droit[5],sharp_gauche[5],sharp_droit[5];
  float volts, moyenne1,moyenne2,moyenne3,moyenne4,moyenne5,moyenne6;
  bool retour;

  for(int i = 0; i < 5; i++)
  {
    sharp_droit[i] = 0;
  }
  for(int i = 0; i < 5; i++)
  {
    sharp_diagonale_droit[i] = 0;
  }
  for(int i = 0; i < 5; i++)
  {
    sharp_gauche[i] = 0;
  }
  for(int i = 0; i < 5; i++)
  {
    sharp_diagonale_gauche[i] = 0;
  }
  for(int i = 0; i < 5; i++)
  {
    sharp_avant_droit[i] = 0;
  }
  for(int i = 0; i < 5; i++)
  {
    sharp_avant_gauche[i] = 0;
  }

  moyenne1 = 0;
   moyenne2 = 0;
    moyenne3 = 0;
     moyenne4 = 0;
      moyenne5 = 0;
       moyenne6 = 0;

  for(int i = 0; i < 5; i++)
  {
    volts = analogRead(pin_sharp_avant_gauche)*0.0048828125; 
    sharp_avant_gauche[i] = 2*13*pow(volts, -1);
    moyenne1 = moyenne1 + sharp_avant_gauche[i];
  }
  moyenne1 = moyenne1 / 5;

  for(int i = 0; i < 5; i++)
  {
    volts = analogRead(pin_sharp_avant_droit)*0.0048828125; 
    sharp_avant_droit[i] = 2*13*pow(volts, -1);
    moyenne2 = moyenne2 + sharp_avant_droit[i];
  }
  moyenne2 = moyenne2 / 5;

  for(int i = 0; i < 5; i++)
  {
    volts = analogRead(pin_sharp_diagonale_gauche)*0.0048828125; 
    sharp_diagonale_gauche[i] = 2*13*pow(volts, -1);
    moyenne3 = moyenne3 + sharp_diagonale_gauche[i];
  }
  moyenne3 = moyenne3 / 5;

  for(int i = 0; i < 5; i++)
  {
    volts = analogRead(pin_sharp_diagonale_droit)*0.0048828125; 
    sharp_diagonale_droit[i] = 2*13*pow(volts, -1);
    moyenne4 = moyenne4 + sharp_diagonale_droit[i];
  }
  moyenne4 = moyenne4 / 5;

  for(int i = 0; i < 5; i++)
  {
    volts = analogRead(pin_sharp_droit)*0.0048828125; 
    sharp_droit[i] = 2*13*pow(volts, -1);
    moyenne5 = moyenne5 + sharp_droit[i];
  }
  moyenne5 = moyenne5 / 5;

  for(int i = 0; i < 5; i++)
  {
    volts = analogRead(pin_sharp_gauche)*0.0048828125; 
    sharp_gauche[i] = 2*13*pow(volts, -1);
    moyenne6 = moyenne6 + sharp_gauche[i];
  }
  moyenne6 = moyenne6 / 5;

  if(avancer == true)
  {
      if(moyenne1 <= valeur_sharp || moyenne2 <= valeur_sharp || moyenne3 <= valeur_sharp || moyenne4 <= valeur_sharp)
      {
          retour = false;
      }
      else
      {
          retour = true;
      }
  }
  else
  {
      if(moyenne1 <= 4 || moyenne2 <= 4 || moyenne6 <= 4 || moyenne5 <= 4)
      {
          retour = false;
      }
      else
      {
        retour = true;
      }
  }
  return retour;
}