#include "Utils.h"

/*void coord_pc(Robot& monRobot)
{
  xbee.print("X = ");
  xbee.println(monRobot.m_x);
  xbee.print("Y = ");
  xbee.println(monRobot.m_y);
  xbee.print("Angle = ");
  xbee.println(monRobot.m_angle);
  xbee.println();
}*/

void demarer_avaler_balle()
{
	digitalWrite(PIN_AVALE_BALLE_1, HIGH);
	digitalWrite(PIN_AVALE_BALLE_2, HIGH);
}

void demarer_canon()
{
	digitalWrite(PIN_CANON, HIGH);
}

void couper_avaler_balle()
{
	digitalWrite(PIN_AVALE_BALLE_1, LOW);
	digitalWrite(PIN_AVALE_BALLE_2, LOW);
}

void couper_canon()
{
	digitalWrite(PIN_CANON, LOW);
}

void init_element_table(Element_table* Objet)
{
	Objet = (Element_table*)malloc(sizeof(Element_table));

	Objet[0].m_x_debut = 0;
	Objet[0].m_x_fin = 78;
	Objet[0].m_y_debut = 38;
	Objet[0].m_y_fin = 42;

	Objet[1].m_x_debut = 222;
	Objet[1].m_x_fin = 300;
	Objet[1].m_y_debut = 38;
	Objet[1].m_y_fin = 42;

	Objet[2].m_x_debut = 0;
	Objet[2].m_x_fin = 180;
	Objet[2].m_y_debut = 61;
	Objet[2].m_y_fin = 118;

	Objet[3].m_x_debut = 300;
	Objet[3].m_x_fin = 282;
	Objet[3].m_y_debut = 61;
	Objet[3].m_y_fin = 118;

	Objet[4].m_x_debut = 85;
	Objet[4].m_x_fin = 215;
	Objet[4].m_y_debut = 110;
	Objet[4].m_y_fin = 200;
}