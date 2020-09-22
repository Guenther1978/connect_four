#ifndef _PLAYING_FIELD_H_
#define _PLAYING_FIELD_H_

/**
 * @file
 * @brief The class PlayingField
 *
 * One instance of the class PlayingField exist in the game
 * "Connect Four"
 */

#include "constants.hpp"

class Spielfeld
{
private:
  char feld[ZEILEN][SPALTEN];
  int anzahl_steine;
public:
  Spielfeld(void);
  friend class Spieler;

  /**
   * @param token to look for
   * @return Are four toekens in the same line?
   */
  bool vierer_reihe_voll(char);

  /** Deletes something*/
  void loesche(void);

  /**
   * @param s number of the column
   * @return Is this column not full?
   */
  bool spalte_nicht_voll(int s)    {return (feld[0][s] == ' ');};

  /**
   * @param r
   * @return number ot the row
   */
  int gebe_zeile(int);

  /**
   * @brief sets a token in the virtual field
   * @param z row
   * @param s column
   * @param c token
   */
  void setze_stein(int z, int s, char c)    {feld[z][s] = c;};
};

#endif
