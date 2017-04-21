#define MATCH 90 // Durée d'un match en secondes (90 sauf test)
#include "Deplacement.h"

void startInt125Hz()
{
  /// Initialiser l'interruption pour l'asservissement Ã  125 Hz avec le Timer 3
  // Prescaler 1/8
  TCCR3B &= ~(1 << CS42);
  TCCR3B |= (1 << CS41);
  TCCR3B &= ~(1 << CS40);
  // Mode CTC (comparaison avec OCR4AH/OCR4AL)
  TCCR3B &= ~(1 << WGM33);
  TCCR3B |= (1 << WGM32);
  TCCR3A &= ~(1 << WGM31);
  TCCR3A &= ~(1 << WGM30);
  // Compter jusqu'Ã  16000(0x3E80)
  OCR3AH = 0x3E; // Toujours écrire l'octet haut d'abord (et lire le bas d'abord)
  OCR3AL = 0x80;
  // Activer l'interruption TIMER3_COMPA
  TIMSK3 |= (1 << OCIE3A);
}

void stopInt125Hz()
{
  // Desactiver l'interruption TIMER4_COMPA
  TIMSK3 &= ~(1 << OCIE3A);
}

volatile int do_asser = 0;
volatile int fin = 0;
volatile int temps = 0;

ISR(TIMER3_COMPA_vect)
{
  ++temps;
  if(temps == MATCH*125)
  {
    arret_moteurs();
    fin = 1;
  }
}
