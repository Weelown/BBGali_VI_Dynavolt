#include "Utils.h"

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

void allonger_robot(Servo m)
{
	m.write(179);
}

void raccourcir_robot(Servo m)
{
	m.write(0);
}

void depart(int pinn)
{
  int depart = 0;
  while(depart != 1)
  {
      depart = digitalRead(pinn);
  }
}
