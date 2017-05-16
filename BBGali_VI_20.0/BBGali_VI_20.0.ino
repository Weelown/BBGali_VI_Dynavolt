#include <math.h>
#include <time.h>
#include "DynamixelSerial2.h"
#include "Robot.h"
#include "Utils.h"
#include <Servo.h>
// #include <SoftwareSerial.h>

#define ABS(a) ( ( (a) > 0 ) ? (a) : (-a) )

													// {0,0} Coté jaune, coté bas à gauche
													// {300,200} coord maximum

#define MOTEUR_DROIT_ID 3
#define MOTEUR_GAUCHE_ID 4

#define pin_sharp_diagonale_gauche A0
#define pin_sharp_diagonale_droit A1
#define pin_sharp_avant_gauche A2
#define pin_sharp_avant_droit A3
#define pin_sharp_gauche A4
#define pin_sharp_droit A5

#define PIN_DEPART 20
#define PIN_RAIL 11

#define PIN_CANON 22
#define PIN_AVALE_BALLE_1 24
#define PIN_AVALE_BALLE_2 26

#define RxEnable 14 //Avt
#define TxEnable 15 

#define PIN_COULEUR A6
#define PIN_STRAT A7




#define TPS_CHECK_SHARP 0.5
#define INCERTITUDE_COORD 0.01

#define valeur_sharp 12

#define ABSCISSE_DEPART 0
#define ORDONNE_DEPART 0
// #define RAYON_DEPART sqrt((ABSCISSE_DEPART^2)+(ORDONNE_DEPART^2))
#define RAYON_DEPART 0
#define ANGLE_DEPART PI

#define VITESSE_MAX_DROITE 500
#define VITESSE_MAX_GAUCHE 500
#define VITESSE_MIN 0

#define RAYON_ENCODEUR 70 // En mm
#define TPS_PER_MM 3.6378272707 // En ms

// SoftwareSerial xbee(A0, A1);
Robot BBGali_VI_Dynavolt;
Servo Rail;
int couleur,strat;

void setup()
{
	// xbee.begin(115200);

	Serial.begin(9600);
 	Dynamixel.begin(1000000,TxEnable,RxEnable);

 	pinMode(PIN_CANON, OUTPUT);
 	pinMode(PIN_AVALE_BALLE_1, OUTPUT);
 	pinMode(PIN_AVALE_BALLE_2, OUTPUT);
 	pinMode(PIN_DEPART, INPUT);
 	pinMode(PIN_COULEUR, INPUT);
  pinMode(PIN_STRAT, INPUT);

	digitalWrite(PIN_CANON, LOW);
	digitalWrite(PIN_AVALE_BALLE_1, LOW);
	digitalWrite(PIN_AVALE_BALLE_2, LOW);
  	Rail.attach(PIN_RAIL);

	Dynamixel.setEndless(3,ON);
	Dynamixel.setEndless(4,ON);
 
 	Serial.println("========== Debut de la transmission ==========");
}

void loop()
{    
    init_robot(BBGali_VI_Dynavolt);
/*
    couleur = digitalRead(PIN_COULEUR);
    
    if(couleur == 0)
    {
      BBGali_VI_Dynavolt.m_x = 0;
      BBGali_VI_Dynavolt.m_y = 0;
      BBGali_VI_Dynavolt.m_x_arrive = 0;
      BBGali_VI_Dynavolt.m_y_arrive = 0;
    }
    else
    {
      BBGali_VI_Dynavolt.m_x = 300;
      BBGali_VI_Dynavolt.m_y = 200;
      BBGali_VI_Dynavolt.m_x_arrive = 300;
      BBGali_VI_Dynavolt.m_y_arrive = 200;
    }

    strat = digitalRead(PIN_STRAT);
    if(strat == 0)
    {
      strat_1(BBGali_VI_Dynavolt);
    }
    else
    {
      strat_2(BBGali_VI_Dynavolt);
    }
    
	  depart(PIN_DEPART);
	  startInt125Hz();
    allonger_robot(Rail);
*/
	// Serial.println("========== Debut de la partie ==========");

  	Dynamixel.turn(3,0,500);
  	//Dynamixel.turn(4,1,500);
  	delay(2000);
  	Dynamixel.turn(3,0,0);
  	Dynamixel.turn(4,0,0);
  	delay(2000);
}

void strat_1(Robot& monRobot)
{}

void strat_2(Robot& monRobot)
{}
