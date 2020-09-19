#ifndef _PLAYING_FIELD_H_
#define _PLAYING_FIELD_H_

/***********************************************************************/
/* Klassen zur Realisierung des Spieles                                */
/***********************************************************************/
// Needed for constants
#include "constants.hpp"

class Spielfeld
{
private:
  char feld[ZEILEN][SPALTEN];
  int anzahl_steine;
public:
  Spielfeld(void);
  friend class Spieler;
  bool vierer_reihe_voll(char);
  void loesche(void);
  bool spalte_nicht_voll(int s)    {return (feld[0][s] == ' ');};
  int gebe_zeile(int);
  void setze_stein(int z, int s, char c)    {feld[z][s] = c;};
};

#endif
