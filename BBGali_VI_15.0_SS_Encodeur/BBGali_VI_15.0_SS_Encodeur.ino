#include <math.h>
#include <time.h>
#include "DynamixelSerial2.h"
#include "Robot.h"
#include "Utils.h"
// #include <SoftwareSerial.h>

#define ABS(a) ( ( (a) > 0 ) ? (a) : (-a) )

													// {0,0} Coté bleu, coté bas à droite
													// {300,200} coord maximum

#define MOTEUR_DROIT_ID 4
#define MOTEUR_GAUCHE_ID 3

#define pin_sharp_diagonale_gauche A0
#define pin_sharp_diagonale_droit A1
#define pin_sharp_avant_gauche A2
#define pin_sharp_avant_droit A3
#define pin_sharp_gauche A4
#define pin_sharp_droit A5

#define PIN_CANON 22
#define PIN_AVALE_BALLE_1 24
#define PIN_AVALE_BALLE_2 26

#define RxEnable 14 //Avt
#define TxEnable 15 

#define TPS_CHECK_SHARP 0.5
#define INCERTITUDE_COORD 0.01
#define TPS_PER_CM 36.378272707  // en ms

#define valeur_sharp 12

#define pi 3.1415926536

#define ABSCISSE_DEPART 0
#define ORDONNE_DEPART 0
// #define RAYON_DEPART sqrt((ABSCISSE_DEPART^2)+(ORDONNE_DEPART^2))
#define RAYON_DEPART 0
#define ANGLE_DEPART pi


#define VITESSE_MAX 500
#define VITESSE_MIN 0

#define MM_PER_TIC 0.0613308801
#define RAYON_ENCODEUR 7


// SoftwareSerial xbee(A0, A1);
Robot BBGali_VI_Dynavolt;
Element_table* Objet;

void setup()
{
	// xbee.begin(115200);
	// startInt125Hz();

	Serial.begin(9600);
	Dynamixel.begin(1000000,TxEnable,RxEnable);

	pinMode(PIN_CANON, OUTPUT); 
	pinMode(PIN_AVALE_BALLE_1, OUTPUT); 
	pinMode(PIN_AVALE_BALLE_2, OUTPUT);

	digitalWrite(PIN_CANON, LOW);
	digitalWrite(PIN_AVALE_BALLE_1, LOW);
	digitalWrite(PIN_AVALE_BALLE_2, LOW);

	Dynamixel.setEndless(3,ON);
	Dynamixel.setEndless(4,ON);

	init_robot(BBGali_VI_Dynavolt);
	init_element_table(Objet);

 	Serial.println("========== Debut de la transmission ==========");
}


void loop()
{
  	Dynamixel.turn(1,0,VITESSE_MAX);
	Dynamixel.turn(2,1,VITESSE_MAX);
	delay(10000);
}