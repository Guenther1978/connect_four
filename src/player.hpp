#ifndef _PLAYER_H_
#define _PLAYER_H_

/***********************************************************************/
/* Klassen zur Realisierung des Spieles                                */
/***********************************************************************/
class Spielfeld;    // Vorwaertsdeklaration

/***********************************************************************/
/**
 * @file
 * @brief The class Player
 *
 * Instances of the class Player exist two times in the
 * game 'connect four'.
 */
class Spieler
{
  private:
  int nummer;
  char spielstein;
  char spielstein_gegner;
  bool ist_mensch;
  bool darf_anfangen;
  int siege;
  public:
  /**
   * @param n The number of the player.
   * @param s The token of this player.
   * @param g The token of the other player.
   * @param m Is he a human beeing or a computer?
   * @param a May he start the first game?
   */
  Spieler(int, char, char, bool, bool);

  /** @return the number of this player.*/
  int gebe_nummer(void)            {return nummer;};

  /** @return the token of this player.*/
  char gebe_stein(void)            {return spielstein;};

  /** @return the token of the other player.*/
  char gebe_stein_gegener(void)    {return spielstein_gegner;};

  /** @return the number of victories.*/
  int gebe_siege(void)             {return siege;};

  /** @return if this player will start the game.*/
  bool gebe_darf_anfangen(void)    {return darf_anfangen;};

  /** @return if this player is a human beeing or a computer.*/
  bool gebe_ist_mensch(void)       {return ist_mensch;};

  /** @brief Increments the number of victories.*/
  void inkrementiere_siege(void)   {siege ++;};

  /** @param a Will this player start the new game?*/
  void setze_darf_anfangen(bool a) {darf_anfangen = a;};

  /**
   * @param reference to the instance of the class playing field.
   * @return number of the column for the next token.
   */
  int waehle_spalte(Spielfeld&);

  /**
   * @param reference to the instance of the class playing field.
   * @param token to look for.
   * @return number of the column for the next token.
   */
  int suche_spalte(Spielfeld&, char);

  /** @brief This function simulates thinking of the computer.*/
  void delay();
};  

#endif
