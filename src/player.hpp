#ifndef _PLAYER_H_
#define _PLAYER_H_

/***********************************************************************/
/* Klassen zur Realisierung des Spieles                                */
/***********************************************************************/
class Spielfeld;    // Vorwaertsdeklaration

/***********************************************************************/
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
  Spieler(int, char, char, bool, bool);
  int gebe_nummer(void)            {return nummer;};
  char gebe_stein(void)            {return spielstein;};
  char gebe_stein_gegener(void)    {return spielstein_gegner;};
  int gebe_siege(void)             {return siege;};
  bool gebe_darf_anfangen(void)    {return darf_anfangen;};
  bool gebe_ist_mensch(void)       {return ist_mensch;};
  void inkrementiere_siege(void)   {siege ++;};
  void setze_darf_anfangen(bool a) {darf_anfangen = a;};
  int waehle_spalte(Spielfeld&);
  int suche_spalte(Spielfeld&, char);
  void delay();
};  

#endif
